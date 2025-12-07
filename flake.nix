{
  description = "melange-webapi Nix Flake";

  inputs.nixpkgs.url = "github:nix-ocaml/nix-overlays";

  outputs = { self, nixpkgs }:
    let
      forAllSystems = f: nixpkgs.lib.genAttrs nixpkgs.lib.systems.flakeExposed (system:
        let
          pkgs = nixpkgs.legacyPackages.${system}.extend (self: super: {
            ocamlPackages = super.ocaml-ng.ocamlPackages_5_4;
          });
        in
        f pkgs);
    in
    {
      packages = forAllSystems (pkgs:
        let
          melange-webapi = with pkgs.ocamlPackages; buildDunePackage {
            pname = "melange-webapi";
            version = "dev";

            src =
              let fs = pkgs.lib.fileset; in
              fs.toSource {
                root = ./.;
                fileset = fs.unions [
                  ./dune-project
                  ./melange-webapi.opam
                  ./src
                  ./tests
                ];
              };

            nativeBuildInputs = with pkgs.ocamlPackages; [ melange reason ];
            propagatedBuildInputs = with pkgs.ocamlPackages; [
              melange
              melange-fetch
            ];
          };
        in
        {
          inherit melange-webapi;
          default = melange-webapi;
        });

      devShells = forAllSystems (pkgs:
        let
          mkShell = { buildInputs ? [ ] }: pkgs.mkShell {
            inputsFrom = [ self.packages.${pkgs.stdenv.hostPlatform.system}.melange-webapi ];
            nativeBuildInputs = with pkgs; [
              yarn
              nodejs_latest
            ] ++ (with pkgs.ocamlPackages; [
              ocamlformat
              merlin
            ]);
            inherit buildInputs;
          };

        in
        {
          default = mkShell { };
          release = mkShell {
            buildInputs = with pkgs; [ cacert curl ocamlPackages.dune-release git ];
          };
        });
    };
}
