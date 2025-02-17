type t = Dom.htmlCollection;

[@mel.scope ("Array", "prototype", "slice")]
external toArray: t => array(Dom.element) = "call";

[@mel.get] external length: t => int = "length";
[@mel.send] [@mel.return nullable]
external item: (int, [@mel.this] t) => option(Dom.element) = "item";
[@mel.send] [@mel.return nullable]
external namedItem: (string, [@mel.this] t) => option(Dom.element) =
  "namedItem";
