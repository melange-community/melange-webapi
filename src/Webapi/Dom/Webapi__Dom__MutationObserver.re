type t = Dom.mutationObserver;

[@mel.new]
external make: ((array(Dom.mutationRecord), t) => unit) => t =
  "MutationObserver";

[@mel.send]
external observe: (Dom.node_like('a), Js.t({..}), [@mel.this] t) => unit =
  "observe";
[@mel.send] external disconnect: ([@mel.this] t) => unit = "disconnect";
[@mel.send]
external takeRecords: ([@mel.this] t) => array(Dom.mutationRecord) =
  "takeRecords";
