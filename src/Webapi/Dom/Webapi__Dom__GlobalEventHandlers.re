/* Mixin */
module Impl = (T: {
                 type t;
               }) => {
  [@mel.send]
  external addSelectionChangeEventListener:
    ([@mel.as "selectionchange"] _, Dom.focusEvent => unit, [@mel.this] T.t) =>
    unit =
    "addEventListener";
  [@mel.send]
  external addSelectionChangeEventListenerWithOptions:
    (
      [@mel.as "selectionchange"] _,
      Dom.focusEvent => unit,
      {
        .
        "capture": bool,
        "once": bool,
        "passive": bool,
      },
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener"; /* not widely supported */
  [@mel.send]
  external addSelectionChangeEventListenerUseCapture:
    (
      [@mel.as "selectionchange"] _,
      Dom.focusEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeSelectionChangeEventListener:
    ([@mel.as "selectionchange"] _, Dom.focusEvent => unit, [@mel.this] T.t) =>
    unit =
    "removeEventListener";
  [@mel.send]
  external removeSelectionChangeEventListenerWithOptions:
    (
      [@mel.as "selectionchange"] _,
      Dom.focusEvent => unit,
      {
        .
        "capture": bool,
        "passive": bool,
      },
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener"; /* not widely supported */
  [@mel.send]
  external removeSelectionChangeEventListenerUseCapture:
    (
      [@mel.as "selectionchange"] _,
      Dom.focusEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";
};
