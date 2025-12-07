type t = Dom.messagePort;

include Webapi__Dom__EventTarget.Impl({
  type nonrec t = t;
});

[@mel.send.pipe: t] external start: unit => unit = "start";
[@mel.send.pipe: t] external close: unit => unit = "close";

[@mel.send.pipe: t] external postMessage: 'a => unit = "postMessage";
[@mel.send.pipe: t] external postMessageWithTransfers: ('a, array(Webapi__Dom__Window.transferable)) => unit = "postMessage";

[@mel.send.pipe: t]
  external addMessageEventListener:
  ([@mel.as "message"] _, Dom.messageEvent => unit) => unit =
  "addEventListener";

[@mel.send.pipe: t]
  external removeMessageEventListener:
  ([@mel.as "message"] _, Dom.messageEvent => unit) => unit =
  "removeEventListener";

[@mel.set]
external setOnMessage: (t, Dom.messageEvent => unit) => unit = "onmessage";
[@mel.set]
external setOnMessageError: (t, Dom.messageEvent => unit) => unit =
  "onmessageerror";
