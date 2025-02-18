type t = Dom.nodeList;

external toArray: t => array(Dom.node) = "Array.prototype.slice.call";

[@mel.send]
external forEach: ((Dom.node, int) => unit, [@mel.this] t) => unit = "forEach";

[@mel.get] external length: t => int = "length";

[@mel.send] [@mel.return nullable]
external item: (int, [@mel.this] t) => option(Dom.node) = "item";
