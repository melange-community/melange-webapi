(lang dune 3.8)

(using melange 0.1)

(name melange-webapi)

(generate_opam_files true)

(source
 (github melange-community/melange-webapi))

(authors "Cheng Lou <chenglou@users.noreply.github.com>")

(maintainers
 "Javier Chávarri <javier.chavarri@gmail.com>"
 "David Sancho <dsnxmoreno@gmail.com>")

(homepage "https://github.com/melange-community/melange-webapi")

(bug_reports "https://github.com/melange-community/melange-webapi/issues")

(license "MIT")

(package
 (name melange-webapi)
 (synopsis "Melange bindings to the DOM")
 (description "Melange bindings to the DOM and other Web APIs.")
 (depends
  ocaml
  (melange
   (>= "5.0.1"))
  melange-fetch
  (reason
   (>= "3.10"))
  (ocaml-lsp-server :with-test)))
