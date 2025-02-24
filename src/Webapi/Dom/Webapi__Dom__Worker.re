type t = Dom.worker;

include Webapi__Dom__EventTarget.Impl({
  type nonrec t = t;
});

[@mel.new] external make: string => t = "Worker";
[@mel.new] external makeWithUrl: Webapi__Url.t => t = "Worker";
[@mel.send.pipe: t] external postMessage: 'a => unit = "postMessage";
[@mel.send.pipe: t] external terminate: unit = "terminate";

[@mel.send.pipe: t]
external addMessageEventListener:
  ([@mel.as "message"] _, Dom.messageEvent => unit) => unit =
  "addEventListener";

[@mel.send.pipe: t]
external removeMessageEventListener:
  ([@mel.as "message"] _, Dom.messageEvent => unit) => unit =
  "removeEventListener";

[@mel.send.pipe: t]
external addMessageErrorEventListener:
  ([@mel.as "message"] _, Dom.messageEvent => unit) => unit =
  "addEventListener";

[@mel.send.pipe: t]
external removeMessageErrorEventListener:
  ([@mel.as "message"] _, Dom.messageEvent => unit) => unit =
  "removeEventListener";

[@mel.set]
external setOnError: (t, Dom.errorEvent => unit) => unit = "onerror";
[@mel.set]
external setOnMessage: (t, Dom.messageEvent => unit) => unit = "onmessage";
[@mel.set]
external setOnMessageError: (t, Dom.messageEvent => unit) => unit =
  "onmessageerror";
