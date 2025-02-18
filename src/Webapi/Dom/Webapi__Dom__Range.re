type t = Dom.range;

[@mel.new] external make: unit => t = "Range"; /* experimental */

[@mel.get] external collapsed: t => bool = "collapsed";
[@mel.get]
external commonAncestorContainer: t => Dom.node = "commonAncestorContainer";
[@mel.get] external endContainer: t => Dom.node = "endContainer";
[@mel.get] external endOffset: t => int = "endOffset";
[@mel.get] external startContainer: t => Dom.node = "startContainer";
[@mel.get] external startOffset: t => int = "startOffset";

[@mel.send]
external setStart: (Dom.node_like('a), int, [@mel.this] t) => unit =
  "setStart";
[@mel.send]
external setEnd: (Dom.node_like('a), int, [@mel.this] t) => unit = "setEnd";
[@mel.send]
external setStartBefore: (Dom.node_like('a), [@mel.this] t) => unit =
  "setStartBefore";
[@mel.send]
external setStartAfter: (Dom.node_like('a), [@mel.this] t) => unit =
  "setStartAfter";
[@mel.send]
external setEndBefore: (Dom.node_like('a), [@mel.this] t) => unit =
  "setEndBefore";
[@mel.send]
external setEndAfter: (Dom.node_like('a), [@mel.this] t) => unit =
  "setEndAfter";
[@mel.send]
external selectNode: (Dom.node_like('a), [@mel.this] t) => unit =
  "selectNode";
[@mel.send]
external selectNodeContents: (Dom.node_like('a), [@mel.this] t) => unit =
  "selectNodeContents";
[@mel.send] external collapse: ([@mel.this] t) => unit = "collapse";
[@mel.send]
external collapseToStart: ([@mel.as {json|true|json}] _, [@mel.this] t) => unit =
  "collapse";
[@mel.send]
external cloneContents: ([@mel.this] t) => Dom.documentFragment =
  "cloneContents";
[@mel.send]
external deleteContents: ([@mel.this] t) => unit = "deleteContents";
[@mel.send]
external extractContents: ([@mel.this] t) => Dom.documentFragment =
  "extractContents";
[@mel.send]
external insertNode: (Dom.node_like('a), [@mel.this] t) => unit =
  "insertNode";
[@mel.send]
external surroundContents: (Dom.node_like('a), [@mel.this] t) => unit =
  "surroundContents";
[@mel.send]
external compareBoundaryPoints:
  (int /* compareHow enum */, t, [@mel.this] t) => int /* compareResult enum */ =
  "compareBoundaryPoints";
let compareBoundaryPoint:
  (Webapi__Dom__Types.compareHow, t, t) => Webapi__Dom__Types.compareResult =
  (how, range, self) =>
    Webapi__Dom__Types.decodeCompareResult(
      compareBoundaryPoints(
        Webapi__Dom__Types.encodeCompareHow(how),
        range,
        self,
      ),
    );
[@mel.send] external cloneRange: ([@mel.this] t) => t = "cloneRange";
[@mel.send] external detach: ([@mel.this] t) => unit = "detach";
[@mel.send] external toString: ([@mel.this] t) => string = "toString";
[@mel.send]
external comparePoint:
  (Dom.node_like('a), int, [@mel.this] t) => int /* compareRsult enum */ =
  "comparePoint";
let comparePoint:
  (Dom.node_like('a), int, t) => Webapi__Dom__Types.compareResult =
  (node, offset, self) =>
    Webapi__Dom__Types.decodeCompareResult(comparePoint(node, offset, self));
[@mel.send]
external createContextualFragment:
  (string, [@mel.this] t) => Dom.documentFragment =
  "createContextualFragment"; /* experimental, but widely supported */
[@mel.send]
external getBoundingClientRect: ([@mel.this] t) => Dom.domRect =
  "getBoundingClientRect"; /* experimental, but widely supported */
[@mel.send]
external getClientRects: ([@mel.this] t) => array(Dom.domRect) =
  "getClientRects"; /* experimental, but widely supported */
[@mel.send]
external intersectsNode: (Dom.node_like('a), [@mel.this] t) => bool =
  "intersectsNode";
[@mel.send]
external isPointInRange: (Dom.node_like('a), int, [@mel.this] t) => bool =
  "isPointInRange";
