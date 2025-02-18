module Impl = (T: {
                 type t;
               }) => {
  external asEventTarget: T.t => Dom.eventTarget = "%identity";

  [@mel.send]
  external addEventListener:
    (string, Dom.event => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addEventListenerWithOptions:
    (
      string,
      Dom.event => unit,
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
  external addEventListenerUseCapture:
    (
      string,
      Dom.event => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeEventListener:
    (string, Dom.event => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeEventListenerWithOptions:
    (
      string,
      Dom.event => unit,
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
  external removeEventListenerUseCapture:
    (
      string,
      Dom.event => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";
  [@mel.send]
  external dispatchEvent: (Dom.event_like('a), [@mel.this] T.t) => bool =
    "dispatchEvent";

  /**
   *  non-standard event-specific functions
   */
  [@mel.send]
  /* UI */
  external addLoadEventListener:
    ([@mel.as "load"] _, Dom.event => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addLoadEventListenerWithOptions:
    (
      [@mel.as "load"] _,
      Dom.event => unit,
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
  external addLoadEventListenerUseCapture:
    (
      [@mel.as "load"] _,
      Dom.event => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeLoadEventListener:
    ([@mel.as "load"] _, Dom.event => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeLoadEventListenerWithOptions:
    (
      [@mel.as "load"] _,
      Dom.event => unit,
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
  external removeLoadEventListenerUseCapture:
    (
      [@mel.as "load"] _,
      Dom.event => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addUnloadEventListener:
    ([@mel.as "unload"] _, Dom.event => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addUnloadEventListenerWithOptions:
    (
      [@mel.as "unload"] _,
      Dom.event => unit,
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
  external addUnloadEventListenerUseCapture:
    (
      [@mel.as "unload"] _,
      Dom.event => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeUnloadEventListener:
    ([@mel.as "unload"] _, Dom.event => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeUnloadEventListenerWithOptions:
    (
      [@mel.as "unload"] _,
      Dom.event => unit,
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
  external removeUnloadEventListenerUseCapture:
    (
      [@mel.as "unload"] _,
      Dom.event => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addAbortEventListener:
    ([@mel.as "abort"] _, Dom.event => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addAbortEventListenerWithOptions:
    (
      [@mel.as "abort"] _,
      Dom.event => unit,
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
  external addAbortEventListenerUseCapture:
    (
      [@mel.as "abort"] _,
      Dom.event => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeAbortEventListener:
    ([@mel.as "abort"] _, Dom.event => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeAbortEventListenerWithOptions:
    (
      [@mel.as "abort"] _,
      Dom.event => unit,
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
  external removeAbortEventListenerUseCapture:
    (
      [@mel.as "abort"] _,
      Dom.event => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addErrorEventListener:
    ([@mel.as "error"] _, Dom.event => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addErrorEventListenerWithOptions:
    (
      [@mel.as "error"] _,
      Dom.event => unit,
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
  external addErrorEventListenerUseCapture:
    (
      [@mel.as "error"] _,
      Dom.event => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeErrorEventListener:
    ([@mel.as "error"] _, Dom.event => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeErrorEventListenerWithOptions:
    (
      [@mel.as "error"] _,
      Dom.event => unit,
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
  external removeErrorEventListenerUseCapture:
    (
      [@mel.as "error"] _,
      Dom.event => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addSelectEventListener:
    ([@mel.as "select"] _, Dom.event => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addSelectEventListenerWithOptions:
    (
      [@mel.as "select"] _,
      Dom.event => unit,
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
  external addSelectEventListenerUseCapture:
    (
      [@mel.as "select"] _,
      Dom.event => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeSelectEventListener:
    ([@mel.as "select"] _, Dom.event => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeSelectEventListenerWithOptions:
    (
      [@mel.as "select"] _,
      Dom.event => unit,
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
  external removeSelectEventListenerUseCapture:
    (
      [@mel.as "select"] _,
      Dom.event => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  /* Focus */

  [@mel.send]
  external addBlurEventListener:
    ([@mel.as "blur"] _, Dom.focusEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addBlurEventListenerWithOptions:
    (
      [@mel.as "blur"] _,
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
  external addBlurEventListenerUseCapture:
    (
      [@mel.as "blur"] _,
      Dom.focusEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeBlurEventListener:
    ([@mel.as "blur"] _, Dom.focusEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeBlurEventListenerWithOptions:
    (
      [@mel.as "blur"] _,
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
  external removeBlurEventListenerUseCapture:
    (
      [@mel.as "blur"] _,
      Dom.focusEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addFocusEventListener:
    ([@mel.as "focus"] _, Dom.focusEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addFocusEventListenerWithOptions:
    (
      [@mel.as "focus"] _,
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
  external addFocusEventListenerUseCapture:
    (
      [@mel.as "focus"] _,
      Dom.focusEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeFocusEventListener:
    ([@mel.as "focus"] _, Dom.focusEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeFocusEventListenerWithOptions:
    (
      [@mel.as "focus"] _,
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
  external removeFocusEventListenerUseCapture:
    (
      [@mel.as "focus"] _,
      Dom.focusEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addFocusInEventListener:
    ([@mel.as "focusin"] _, Dom.focusEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addFocusInEventListenerWithOptions:
    (
      [@mel.as "focusin"] _,
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
  external addFocusInEventListenerUseCapture:
    (
      [@mel.as "focusin"] _,
      Dom.focusEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeFocusInEventListener:
    ([@mel.as "focusin"] _, Dom.focusEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeFocusInEventListenerWithOptions:
    (
      [@mel.as "focusin"] _,
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
  external removeFocusInEventListenerUseCapture:
    (
      [@mel.as "focusin"] _,
      Dom.focusEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addFocusOutEventListener:
    ([@mel.as "focusout"] _, Dom.focusEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addFocusOutEventListenerWithOptions:
    (
      [@mel.as "focusout"] _,
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
  external addFocusOutEventListenerUseCapture:
    (
      [@mel.as "focusout"] _,
      Dom.focusEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeFocusOutEventListener:
    ([@mel.as "focusout"] _, Dom.focusEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeFocusOutEventListenerWithOptions:
    (
      [@mel.as "focusout"] _,
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
  external removeFocusOutEventListenerUseCapture:
    (
      [@mel.as "focusout"] _,
      Dom.focusEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  /* Mouse */

  [@mel.send]
  external addClickEventListener:
    ([@mel.as "click"] _, Dom.mouseEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addClickEventListenerWithOptions:
    (
      [@mel.as "click"] _,
      Dom.mouseEvent => unit,
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
  external addClickEventListenerUseCapture:
    (
      [@mel.as "click"] _,
      Dom.mouseEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeClickEventListener:
    ([@mel.as "click"] _, Dom.mouseEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeClickEventListenerWithOptions:
    (
      [@mel.as "click"] _,
      Dom.mouseEvent => unit,
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
  external removeClickEventListenerUseCapture:
    (
      [@mel.as "click"] _,
      Dom.mouseEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addDblClickEventListener:
    ([@mel.as "dblclick"] _, Dom.mouseEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addDblClickEventListenerWithOptions:
    (
      [@mel.as "dblclick"] _,
      Dom.mouseEvent => unit,
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
  external addDblClickEventListenerUseCapture:
    (
      [@mel.as "dblclick"] _,
      Dom.mouseEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeDblClickEventListener:
    ([@mel.as "dblclick"] _, Dom.mouseEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeDblClickEventListenerWithOptions:
    (
      [@mel.as "dblclick"] _,
      Dom.mouseEvent => unit,
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
  external removeDblClickEventListenerUseCapture:
    (
      [@mel.as "dblclick"] _,
      Dom.mouseEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addMouseDownEventListener:
    ([@mel.as "mousedown"] _, Dom.mouseEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addMouseDownEventListenerWithOptions:
    (
      [@mel.as "mousedown"] _,
      Dom.mouseEvent => unit,
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
  external addMouseDownEventListenerUseCapture:
    (
      [@mel.as "mousedown"] _,
      Dom.mouseEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeMouseDownEventListener:
    ([@mel.as "mousedown"] _, Dom.mouseEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeMouseDownEventListenerWithOptions:
    (
      [@mel.as "mousedown"] _,
      Dom.mouseEvent => unit,
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
  external removeMouseDownEventListenerUseCapture:
    (
      [@mel.as "mousedown"] _,
      Dom.mouseEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addMouseEnterEventListener:
    ([@mel.as "mouseenter"] _, Dom.mouseEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addMouseEnterEventListenerWithOptions:
    (
      [@mel.as "mouseenter"] _,
      Dom.mouseEvent => unit,
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
  external addMouseEnterEventListenerUseCapture:
    (
      [@mel.as "mouseenter"] _,
      Dom.mouseEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeMouseEnterEventListener:
    ([@mel.as "mouseenter"] _, Dom.mouseEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeMouseEnterEventListenerWithOptions:
    (
      [@mel.as "mouseenter"] _,
      Dom.mouseEvent => unit,
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
  external removeMouseEnterEventListenerUseCapture:
    (
      [@mel.as "mouseenter"] _,
      Dom.mouseEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addMouseMoveEventListener:
    ([@mel.as "mousemove"] _, Dom.mouseEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addMouseMoveEventListenerWithOptions:
    (
      [@mel.as "mousemove"] _,
      Dom.mouseEvent => unit,
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
  external addMouseMoveEventListenerUseCapture:
    (
      [@mel.as "mousemove"] _,
      Dom.mouseEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeMouseMoveEventListener:
    ([@mel.as "mousemove"] _, Dom.mouseEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeMouseMoveEventListenerWithOptions:
    (
      [@mel.as "mousemove"] _,
      Dom.mouseEvent => unit,
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
  external removeMouseMoveEventListenerUseCapture:
    (
      [@mel.as "mousemove"] _,
      Dom.mouseEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addMouseOutEventListener:
    ([@mel.as "mouseout"] _, Dom.mouseEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addMouseOutEventListenerWithOptions:
    (
      [@mel.as "mouseout"] _,
      Dom.mouseEvent => unit,
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
  external addMouseOutEventListenerUseCapture:
    (
      [@mel.as "mouseout"] _,
      Dom.mouseEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeMouseOutEventListener:
    ([@mel.as "mouseout"] _, Dom.mouseEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeMouseOutEventListenerWithOptions:
    (
      [@mel.as "mouseout"] _,
      Dom.mouseEvent => unit,
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
  external removeMouseOutEventListenerUseCapture:
    (
      [@mel.as "mouseout"] _,
      Dom.mouseEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addMouseOverEventListener:
    ([@mel.as "mouseover"] _, Dom.mouseEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addMouseOverEventListenerWithOptions:
    (
      [@mel.as "mouseover"] _,
      Dom.mouseEvent => unit,
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
  external addMouseOverEventListenerUseCapture:
    (
      [@mel.as "mouseover"] _,
      Dom.mouseEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeMouseOverEventListener:
    ([@mel.as "mouseover"] _, Dom.mouseEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeMouseOverEventListenerWithOptions:
    (
      [@mel.as "mouseover"] _,
      Dom.mouseEvent => unit,
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
  external removeMouseOverEventListenerUseCapture:
    (
      [@mel.as "mouseover"] _,
      Dom.mouseEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addMouseUpEventListener:
    ([@mel.as "mouseup"] _, Dom.mouseEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addMouseUpEventListenerWithOptions:
    (
      [@mel.as "mouseup"] _,
      Dom.mouseEvent => unit,
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
  external addMouseUpEventListenerUseCapture:
    (
      [@mel.as "mouseup"] _,
      Dom.mouseEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeMouseUpEventListener:
    ([@mel.as "mouseup"] _, Dom.mouseEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeMouseUpEventListenerWithOptions:
    (
      [@mel.as "mouseup"] _,
      Dom.mouseEvent => unit,
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
  external removeMouseUpEventListenerUseCapture:
    (
      [@mel.as "mouseup"] _,
      Dom.mouseEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  /* Wheel */

  [@mel.send]
  external addWheelEventListener:
    ([@mel.as "wheel"] _, Dom.wheelEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addWheelEventListenerWithOptions:
    (
      [@mel.as "wheel"] _,
      Dom.wheelEvent => unit,
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
  external addWheelEventListenerUseCapture:
    (
      [@mel.as "wheel"] _,
      Dom.wheelEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeWheelEventListener:
    ([@mel.as "wheel"] _, Dom.wheelEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeWheelEventListenerWithOptions:
    (
      [@mel.as "wheel"] _,
      Dom.wheelEvent => unit,
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
  external removeWheelEventListenerUseCapture:
    (
      [@mel.as "wheel"] _,
      Dom.wheelEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  /* Input */

  [@mel.send]
  external addBeforeInputEventListener:
    ([@mel.as "beforeinput"] _, Dom.inputEvent => unit, [@mel.this] T.t) =>
    unit =
    "addEventListener";
  [@mel.send]
  external addBeforeInputEventListenerWithOptions:
    (
      [@mel.as "beforeinput"] _,
      Dom.inputEvent => unit,
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
  external addBeforeInputEventListenerUseCapture:
    (
      [@mel.as "beforeinput"] _,
      Dom.inputEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeBeforeInputEventListener:
    ([@mel.as "beforeinput"] _, Dom.inputEvent => unit, [@mel.this] T.t) =>
    unit =
    "removeEventListener";
  [@mel.send]
  external removeBeforeInputEventListenerWithOptions:
    (
      [@mel.as "beforeinput"] _,
      Dom.inputEvent => unit,
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
  external removeBeforeInputEventListenerUseCapture:
    (
      [@mel.as "beforeinput"] _,
      Dom.inputEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addInputEventListener:
    ([@mel.as "input"] _, Dom.inputEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addInputEventListenerWithOptions:
    (
      [@mel.as "input"] _,
      Dom.inputEvent => unit,
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
  external addInputEventListenerUseCapture:
    (
      [@mel.as "input"] _,
      Dom.inputEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeInputEventListener:
    ([@mel.as "input"] _, Dom.inputEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeInputEventListenerWithOptions:
    (
      [@mel.as "input"] _,
      Dom.inputEvent => unit,
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
  external removeInputEventListenerUseCapture:
    (
      [@mel.as "input"] _,
      Dom.inputEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  /* Keyboard */

  [@mel.send]
  external addKeyDownEventListener:
    ([@mel.as "keydown"] _, Dom.keyboardEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addKeyDownEventListenerWithOptions:
    (
      [@mel.as "keydown"] _,
      Dom.keyboardEvent => unit,
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
  external addKeyDownEventListenerUseCapture:
    (
      [@mel.as "keydown"] _,
      Dom.keyboardEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeKeyDownEventListener:
    ([@mel.as "keydown"] _, Dom.keyboardEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeKeyDownEventListenerWithOptions:
    (
      [@mel.as "keydown"] _,
      Dom.keyboardEvent => unit,
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
  external removeKeyDownEventListenerUseCapture:
    (
      [@mel.as "keydown"] _,
      Dom.keyboardEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addKeyUpEventListener:
    ([@mel.as "keyup"] _, Dom.keyboardEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addKeyUpEventListenerWithOptions:
    (
      [@mel.as "keyup"] _,
      Dom.keyboardEvent => unit,
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
  external addKeyUpEventListenerUseCapture:
    (
      [@mel.as "keyup"] _,
      Dom.keyboardEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeKeyUpEventListener:
    ([@mel.as "keyup"] _, Dom.keyboardEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeKeyUpEventListenerWithOptions:
    (
      [@mel.as "keyup"] _,
      Dom.keyboardEvent => unit,
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
  external removeKeyUpEventListenerUseCapture:
    (
      [@mel.as "keyup"] _,
      Dom.keyboardEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addKeyPressEventListener:
    ([@mel.as "keypress"] _, Dom.keyboardEvent => unit, [@mel.this] T.t) =>
    unit =
    "addEventListener";
  [@mel.send]
  external addKeyPressEventListenerWithOptions:
    (
      [@mel.as "keypress"] _,
      Dom.keyboardEvent => unit,
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
  external addKeyPressEventListenerUseCapture:
    (
      [@mel.as "keypress"] _,
      Dom.keyboardEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeKeyPressEventListener:
    ([@mel.as "keypress"] _, Dom.keyboardEvent => unit, [@mel.this] T.t) =>
    unit =
    "removeEventListener";
  [@mel.send]
  external removeKeyPressEventListenerWithOptions:
    (
      [@mel.as "keypress"] _,
      Dom.keyboardEvent => unit,
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
  external removeKeyPressEventListenerUseCapture:
    (
      [@mel.as "keypress"] _,
      Dom.keyboardEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  /* Composition */

  [@mel.send]
  external addCompositionStartEventListener:
    (
      [@mel.as "compositionstart"] _,
      Dom.compositionEvent => unit,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external addCompositionStartEventListenerWithOptions:
    (
      [@mel.as "compositionstart"] _,
      Dom.compositionEvent => unit,
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
  external addCompositionStartEventListenerUseCapture:
    (
      [@mel.as "compositionstart"] _,
      Dom.compositionEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeCompositionStartEventListener:
    (
      [@mel.as "compositionstart"] _,
      Dom.compositionEvent => unit,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";
  [@mel.send]
  external removeCompositionStartEventListenerWithOptions:
    (
      [@mel.as "compositionstart"] _,
      Dom.compositionEvent => unit,
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
  external removeCompositionStartEventListenerUseCapture:
    (
      [@mel.as "compositionstart"] _,
      Dom.compositionEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addCompositionUpdateEventListener:
    (
      [@mel.as "compositionupdate"] _,
      Dom.compositionEvent => unit,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external addCompositionUpdateEventListenerWithOptions:
    (
      [@mel.as "compositionupdate"] _,
      Dom.compositionEvent => unit,
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
  external addCompositionUpdateEventListenerUseCapture:
    (
      [@mel.as "compositionupdate"] _,
      Dom.compositionEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeCompositionUpdateEventListener:
    (
      [@mel.as "compositionupdate"] _,
      Dom.compositionEvent => unit,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";
  [@mel.send]
  external removeCompositionUpdateEventListenerWithOptions:
    (
      [@mel.as "compositionupdate"] _,
      Dom.compositionEvent => unit,
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
  external removeCompositionUpdateEventListenerUseCapture:
    (
      [@mel.as "compositionupdate"] _,
      Dom.compositionEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addCompositionEndEventListener:
    (
      [@mel.as "compositionend"] _,
      Dom.compositionEvent => unit,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external addCompositionEndEventListenerWithOptions:
    (
      [@mel.as "compositionend"] _,
      Dom.compositionEvent => unit,
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
  external addCompositionEndEventListenerUseCapture:
    (
      [@mel.as "compositionend"] _,
      Dom.compositionEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeCompositionEndEventListener:
    (
      [@mel.as "compositionend"] _,
      Dom.compositionEvent => unit,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";
  [@mel.send]
  external removeCompositionEndEventListenerWithOptions:
    (
      [@mel.as "compositionend"] _,
      Dom.compositionEvent => unit,
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
  external removeCompositionEndEventListenerUseCapture:
    (
      [@mel.as "compositionend"] _,
      Dom.compositionEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  /* Drag */

  [@mel.send]
  external addDragEventListener:
    ([@mel.as "drag"] _, Dom.dragEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addDragEventListenerWithOptions:
    (
      [@mel.as "drag"] _,
      Dom.dragEvent => unit,
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
  external addDragEventListenerUseCapture:
    (
      [@mel.as "drag"] _,
      Dom.dragEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeDragEventListener:
    ([@mel.as "drag"] _, Dom.dragEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeDragEventListenerWithOptions:
    (
      [@mel.as "drag"] _,
      Dom.dragEvent => unit,
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
  external removeDragEventListenerUseCapture:
    (
      [@mel.as "drag"] _,
      Dom.dragEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addDragEndEventListener:
    ([@mel.as "dragend"] _, Dom.dragEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addDragEndEventListenerWithOptions:
    (
      [@mel.as "dragend"] _,
      Dom.dragEvent => unit,
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
  external addDragEndEventListenerUseCapture:
    (
      [@mel.as "dragend"] _,
      Dom.dragEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeDragEndEventListener:
    ([@mel.as "dragend"] _, Dom.dragEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeDragEndEventListenerWithOptions:
    (
      [@mel.as "dragend"] _,
      Dom.dragEvent => unit,
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
  external removeDragEndEventListenerUseCapture:
    (
      [@mel.as "dragend"] _,
      Dom.dragEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addDragEnterEventListener:
    ([@mel.as "dragenter"] _, Dom.dragEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addDragEnterEventListenerWithOptions:
    (
      [@mel.as "dragenter"] _,
      Dom.dragEvent => unit,
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
  external addDragEnterEventListenerUseCapture:
    (
      [@mel.as "dragenter"] _,
      Dom.dragEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeDragEnterEventListener:
    ([@mel.as "dragenter"] _, Dom.dragEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeDragEnterEventListenerWithOptions:
    (
      [@mel.as "dragenter"] _,
      Dom.dragEvent => unit,
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
  external removeDragEnterEventListenerUseCapture:
    (
      [@mel.as "dragenter"] _,
      Dom.dragEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addDragExitEventListener:
    ([@mel.as "dragexit"] _, Dom.dragEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addDragExitEventListenerWithOptions:
    (
      [@mel.as "dragexit"] _,
      Dom.dragEvent => unit,
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
  external addDragExitEventListenerUseCapture:
    (
      [@mel.as "dragexit"] _,
      Dom.dragEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeDragExitEventListener:
    ([@mel.as "dragexit"] _, Dom.dragEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeDragExitEventListenerWithOptions:
    (
      [@mel.as "dragexit"] _,
      Dom.dragEvent => unit,
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
  external removeDragExitEventListenerUseCapture:
    (
      [@mel.as "dragexit"] _,
      Dom.dragEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addDragLeaveEventListener:
    ([@mel.as "dragleave"] _, Dom.dragEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addDragLeaveEventListenerWithOptions:
    (
      [@mel.as "dragleave"] _,
      Dom.dragEvent => unit,
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
  external addDragLeaveEventListenerUseCapture:
    (
      [@mel.as "dragleave"] _,
      Dom.dragEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeDragLeaveEventListener:
    ([@mel.as "dragleave"] _, Dom.dragEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeDragLeaveEventListenerWithOptions:
    (
      [@mel.as "dragleave"] _,
      Dom.dragEvent => unit,
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
  external removeDragLeaveEventListenerUseCapture:
    (
      [@mel.as "dragleave"] _,
      Dom.dragEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addDragOverEventListener:
    ([@mel.as "dragover"] _, Dom.dragEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addDragOverEventListenerWithOptions:
    (
      [@mel.as "dragover"] _,
      Dom.dragEvent => unit,
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
  external addDragOverEventListenerUseCapture:
    (
      [@mel.as "dragover"] _,
      Dom.dragEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeDragOverEventListener:
    ([@mel.as "dragover"] _, Dom.dragEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeDragOverEventListenerWithOptions:
    (
      [@mel.as "dragover"] _,
      Dom.dragEvent => unit,
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
  external removeDragOverEventListenerUseCapture:
    (
      [@mel.as "dragover"] _,
      Dom.dragEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addDragStartEventListener:
    ([@mel.as "dragstart"] _, Dom.dragEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addDragStartEventListenerWithOptions:
    (
      [@mel.as "dragstart"] _,
      Dom.dragEvent => unit,
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
  external addDragStartEventListenerUseCapture:
    (
      [@mel.as "dragstart"] _,
      Dom.dragEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeDragStartEventListener:
    ([@mel.as "dragstart"] _, Dom.dragEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeDragStartEventListenerWithOptions:
    (
      [@mel.as "dragstart"] _,
      Dom.dragEvent => unit,
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
  external removeDragStartEventListenerUseCapture:
    (
      [@mel.as "dragstart"] _,
      Dom.dragEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addDropEventListener:
    ([@mel.as "drop"] _, Dom.dragEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addDropEventListenerWithOptions:
    (
      [@mel.as "drop"] _,
      Dom.dragEvent => unit,
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
  external addDropEventListenerUseCapture:
    (
      [@mel.as "drop"] _,
      Dom.dragEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeDropEventListener:
    ([@mel.as "drop"] _, Dom.dragEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeDropEventListenerWithOptions:
    (
      [@mel.as "drop"] _,
      Dom.dragEvent => unit,
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
  external removeDropEventListenerUseCapture:
    (
      [@mel.as "drop"] _,
      Dom.dragEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  /* Touch */

  [@mel.send]
  external addTouchCancelEventListener:
    ([@mel.as "touchcancel"] _, Dom.touchEvent => unit, [@mel.this] T.t) =>
    unit =
    "addEventListener";
  [@mel.send]
  external addTouchCancelEventListenerWithOptions:
    (
      [@mel.as "touchcancel"] _,
      Dom.touchEvent => unit,
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
  external addTouchCancelEventListenerUseCapture:
    (
      [@mel.as "touchcancel"] _,
      Dom.touchEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeTouchCancelEventListener:
    ([@mel.as "touchcancel"] _, Dom.touchEvent => unit, [@mel.this] T.t) =>
    unit =
    "removeEventListener";
  [@mel.send]
  external removeTouchCancelEventListenerWithOptions:
    (
      [@mel.as "touchcancel"] _,
      Dom.touchEvent => unit,
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
  external removeTouchCancelEventListenerUseCapture:
    (
      [@mel.as "touchcancel"] _,
      Dom.touchEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addTouchEndEventListener:
    ([@mel.as "touchend"] _, Dom.touchEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addTouchEndEventListenerWithOptions:
    (
      [@mel.as "touchend"] _,
      Dom.touchEvent => unit,
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
  external addTouchEndEventListenerUseCapture:
    (
      [@mel.as "touchend"] _,
      Dom.touchEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeTouchEndEventListener:
    ([@mel.as "touchend"] _, Dom.touchEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeTouchEndEventListenerWithOptions:
    (
      [@mel.as "touchend"] _,
      Dom.touchEvent => unit,
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
  external removeTouchEndEventListenerUseCapture:
    (
      [@mel.as "touchend"] _,
      Dom.touchEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addTouchMoveEventListener:
    ([@mel.as "touchmove"] _, Dom.touchEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addTouchMoveEventListenerWithOptions:
    (
      [@mel.as "touchmove"] _,
      Dom.touchEvent => unit,
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
  external addTouchMoveEventListenerUseCapture:
    (
      [@mel.as "touchmove"] _,
      Dom.touchEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeTouchMoveEventListener:
    ([@mel.as "touchmove"] _, Dom.touchEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeTouchMoveEventListenerWithOptions:
    (
      [@mel.as "touchmove"] _,
      Dom.touchEvent => unit,
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
  external removeTouchMoveEventListenerUseCapture:
    (
      [@mel.as "touchmove"] _,
      Dom.touchEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addTouchStartEventListener:
    ([@mel.as "touchstart"] _, Dom.touchEvent => unit, [@mel.this] T.t) => unit =
    "addEventListener";
  [@mel.send]
  external addTouchStartEventListenerWithOptions:
    (
      [@mel.as "touchstart"] _,
      Dom.touchEvent => unit,
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
  external addTouchStartEventListenerUseCapture:
    (
      [@mel.as "touchstart"] _,
      Dom.touchEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeTouchStartEventListener:
    ([@mel.as "touchstart"] _, Dom.touchEvent => unit, [@mel.this] T.t) => unit =
    "removeEventListener";
  [@mel.send]
  external removeTouchStartEventListenerWithOptions:
    (
      [@mel.as "touchstart"] _,
      Dom.touchEvent => unit,
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
  external removeTouchStartEventListenerUseCapture:
    (
      [@mel.as "touchstart"] _,
      Dom.touchEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  /* Animation */

  [@mel.send]
  external addAnimationCancelEventListener:
    (
      [@mel.as "animationcancel"] _,
      Dom.animationEvent => unit,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external addAnimationCancelEventListenerWithOptions:
    (
      [@mel.as "animationcancel"] _,
      Dom.animationEvent => unit,
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
  external addAnimationCancelEventListenerUseCapture:
    (
      [@mel.as "animationcancel"] _,
      Dom.animationEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeAnimationCancelEventListener:
    (
      [@mel.as "animationcancel"] _,
      Dom.animationEvent => unit,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";
  [@mel.send]
  external removeAnimationCancelEventListenerWithOptions:
    (
      [@mel.as "animationcancel"] _,
      Dom.animationEvent => unit,
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
  external removeAnimationCancelEventListenerUseCapture:
    (
      [@mel.as "animationcancel"] _,
      Dom.animationEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addAnimationEndEventListener:
    (
      [@mel.as "animationend"] _,
      Dom.animationEvent => unit,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external addAnimationEndEventListenerWithOptions:
    (
      [@mel.as "animationend"] _,
      Dom.animationEvent => unit,
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
  external addAnimationEndEventListenerUseCapture:
    (
      [@mel.as "animationend"] _,
      Dom.animationEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeAnimationEndEventListener:
    (
      [@mel.as "animationend"] _,
      Dom.animationEvent => unit,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";
  [@mel.send]
  external removeAnimationEndEventListenerWithOptions:
    (
      [@mel.as "animationend"] _,
      Dom.animationEvent => unit,
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
  external removeAnimationEndEventListenerUseCapture:
    (
      [@mel.as "animationend"] _,
      Dom.animationEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addAnimationIterationEventListener:
    (
      [@mel.as "animationiteration"] _,
      Dom.animationEvent => unit,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external addAnimationIterationEventListenerWithOptions:
    (
      [@mel.as "animationiteration"] _,
      Dom.animationEvent => unit,
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
  external addAnimationIterationEventListenerUseCapture:
    (
      [@mel.as "animationiteration"] _,
      Dom.animationEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeAnimationIterationEventListener:
    (
      [@mel.as "animationiteration"] _,
      Dom.animationEvent => unit,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";
  [@mel.send]
  external removeAnimationIterationEventListenerWithOptions:
    (
      [@mel.as "animationiteration"] _,
      Dom.animationEvent => unit,
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
  external removeAnimationIterationEventListenerUseCapture:
    (
      [@mel.as "animationiteration"] _,
      Dom.animationEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";

  [@mel.send]
  external addAnimationStartEventListener:
    (
      [@mel.as "animationstart"] _,
      Dom.animationEvent => unit,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external addAnimationStartEventListenerWithOptions:
    (
      [@mel.as "animationstart"] _,
      Dom.animationEvent => unit,
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
  external addAnimationStartEventListenerUseCapture:
    (
      [@mel.as "animationstart"] _,
      Dom.animationEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removeAnimationStartEventListener:
    (
      [@mel.as "animationstart"] _,
      Dom.animationEvent => unit,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";
  [@mel.send]
  external removeAnimationStartEventListenerWithOptions:
    (
      [@mel.as "animationstart"] _,
      Dom.animationEvent => unit,
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
  external removeAnimationStartEventListenerUseCapture:
    (
      [@mel.as "animationstart"] _,
      Dom.animationEvent => unit,
      [@mel.as {json|true|json}] _,
      [@mel.this] T.t
    ) =>
    unit =
    "removeEventListener";
};

include Impl({
  type nonrec t = Dom.eventTarget;
});

external unsafeAsDocument: Dom.eventTarget => Dom.document = "%identity";
external unsafeAsElement: Dom.eventTarget => Dom.element = "%identity";
external unsafeAsWindow: Dom.eventTarget => Dom.window = "%identity";
