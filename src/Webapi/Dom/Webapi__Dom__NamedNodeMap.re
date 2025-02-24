type t = Dom.namedNodeMap;

[@mel.get] external length: t => int = "length";

[@mel.send] [@mel.return nullable]
external item: (int, [@mel.this] t) => option(Dom.attr) = "item";
[@mel.send] [@mel.return nullable]
external getNamedItem: (string, [@mel.this] t) => option(Dom.attr) =
  "getNamedItem";
[@mel.send] [@mel.return nullable]
external getNamedItemNS: (string, string, [@mel.this] t) => option(Dom.attr) =
  "getNamedItemNS";
[@mel.send]
external setNamedItem: (Dom.attr, [@mel.this] t) => unit = "setNamedItem";
[@mel.send]
external setNamedItemNS: (Dom.attr, [@mel.this] t) => unit = "setNamedItemNS";
[@mel.send]
external removeNamedItem: (string, [@mel.this] t) => Dom.attr =
  "removeNamedItem";
[@mel.send]
external removeNamedItemNS: (string, string, [@mel.this] t) => Dom.attr =
  "removeNamedItemNS";

[@mel.scope ("Array", "prototype", "slice")]
external toArray: t => array(Dom.attr) = "call";
