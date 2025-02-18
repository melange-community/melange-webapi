type t = Dom.domImplementation;

[@mel.send]
external createDocumentType:
  (
    ~qualifiedName: string,
    ~publicId: string,
    ~systemId: string,
    [@mel.this] t
  ) =>
  Dom.documentType =
  "createDocumentType";
[@mel.send]
external createDocument:
  (Js.null(string), string, Js.null(Dom.documentType), [@mel.this] t) =>
  Dom.xmlDocument =
  "createDocument";
let createDocument =
    (
      ~namespace: option(string)=?,
      ~qualifiedName: string,
      ~docType: option(Dom.documentType)=?,
    ) =>
  createDocument(
    Js.Null.fromOption(namespace),
    qualifiedName,
    Js.Null.fromOption(docType),
  );
[@mel.send]
external createHTMLDocument: ([@mel.this] t) => Dom.htmlDocument =
  "createHTMLDocument";
[@mel.send]
external createHTMLDocumentWithTitle:
  (string, [@mel.this] t) => Dom.htmlDocument =
  "createHTMLDocument";
[@mel.send] external hasFeature: ([@mel.this] t) => bool = "hasFeature"; /* useless; always returns true (this is exact wording from the actual spec) */
