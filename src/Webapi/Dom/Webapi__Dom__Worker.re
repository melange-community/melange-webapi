type t = Dom.worker

include Webapi__Dom__EventTarget.Impl({
  type nonrec t = t;
});

[@mel.new] external make: string => t = "Worker";
[@mel.send.pipe: t] external postMessage: (Js.t({..})) => unit = "postMessage";
[@mel.send.pipe: t] external terminate: unit => unit = "terminate";

[@mel.set] external setOnError: (t, Dom.errorEvent => unit) => unit = "onerror";
[@mel.set] external setOnMessage: (t, Dom.messageEvent => unit) => unit = "onmessage";
[@mel.set] external setOnMessageError: (t, Dom.messageEvent => unit) => unit = "onmessageerror";
