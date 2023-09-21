{
  description = "melange-webapi Nix Flake";

  inputs.nix-filter.url = "github:numtide/nix-filter";
  inputs.flake-utils.url = "github:numtide/flake-utils";
  inputs.nixpkgs = {
    url = "github:nix-ocaml/nix-overlays";
    inputs.flake-utils.follows = "flake-utils";
  };
  inputs.melange-src = {
    url = "github:melange-re/melange";
    inputs.nix-filter.follows = "nix-filter";
    inputs.flake-utils.follows = "flake-utils";
    inputs.nixpkgs.follows = "nixpkgs";
  };

  outputs = { self, nixpkgs, flake-utils, nix-filter, melange-src }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages."${system}".appendOverlays [
          (self: super: {
            ocamlPackages = super.ocaml-ng.ocamlPackages_5_1.overrideScope' (oself: osuper: {
              ppxlib = osuper.ppxlib.overrideAttrs (_: {
                src = super.fetchFromGitHub {
                  owner = "ocaml-ppx";
                  repo = "ppxlib";
                  rev = "4026b795d9b9bd44beaf11b790a7f9a26fc0aa63";
                  hash = "sha256-dRWHkE9aZS7gQp5CAT8qCX/uKYEbiIy7our5XXgMHGI=";
                };

              });
            });
          })
          melange-src.overlays.default
        ];
        inherit (pkgs) nodejs_latest lib stdenv darwin;

        melange-json = with pkgs.ocamlPackages; buildDunePackage {
          pname = "melange-webapi";
          version = "dev";

          src = ./.;
          nativeBuildInputs = with pkgs.ocamlPackages; [ melange reason ];
          propagatedBuildInputs = with pkgs.ocamlPackages; [
            melange
            melange-fetch
          ];
        };

        mkShell = { buildInputs ? [ ] }: pkgs.mkShell {
          inputsFrom = [ melange-json ];
          nativeBuildInputs = with pkgs; [
            yarn
            nodejs_latest
          ] ++ (with pkgs.ocamlPackages; [
            ocamlformat
            merlin
            melange-jest
          ]);
          inherit buildInputs;
        };
      in
      rec {
        packages.default = melange-json;
        devShells = {
          default = mkShell { };
          release = mkShell {
            buildInputs = with pkgs; [ cacert curl ocamlPackages.dune-release git ];
          };
        };
      });
}
