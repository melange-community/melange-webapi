type t = Dom.selection;

[@mel.get] [@mel.return nullable]
external anchorNode: t => option(Dom.node) = "anchorNode";
[@mel.get] external anchorOffset: t => int = "anchorOffset";
[@mel.get] [@mel.return nullable]
external focusNode: t => option(Dom.node) = "focusNode";
[@mel.get] external focusOffset: t => int = "focusOffset";
[@mel.get] external isCollapsed: t => bool = "isCollapsed";
[@mel.get] external rangeCount: t => int = "rangeCount";

[@mel.send]
external getRangeAt: (int, [@mel.this] t) => Dom.range = "getRangeAt";
[@mel.send]
external collapse: (Dom.node_like(_), int, [@mel.this] t) => unit =
  "collapse";
[@mel.send]
external extend: (Dom.node_like(_), int, [@mel.this] t) => unit = "extend";
[@mel.send]
external collapseToStart: ([@mel.this] t) => unit = "collapseToStart";
[@mel.send] external collapseToEnd: ([@mel.this] t) => unit = "collapseToEnd";
[@mel.send]
external selectAllChildren: (Dom.node_like(_), [@mel.this] t) => unit =
  "selectAllChildren";
[@mel.send]
external setBaseAndExtent:
  (Dom.node_like(_), int, Dom.node_like(_), int, [@mel.this] t) => unit =
  "setBaseAndExtent";
[@mel.send] external addRange: (Dom.range, [@mel.this] t) => unit = "addRange";
[@mel.send]
external removeRange: (Dom.range, [@mel.this] t) => unit = "removeRange";
[@mel.send]
external removeAllRanges: ([@mel.this] t) => unit = "removeAllRanges";
[@mel.send]
external deleteFromDocument: ([@mel.this] t) => unit = "deleteFromDocument";
[@mel.send] external toString: ([@mel.this] t) => string = "toString";
[@mel.send]
external containsNode:
  (Dom.node_like(_), [@mel.as {json|false|json}] _, [@mel.this] t) => bool =
  "containsNode";
[@mel.send]
external containsNodePartly:
  (Dom.node_like(_), [@mel.as {json|true|json}] _, [@mel.this] t) => bool =
  "containsNode";
