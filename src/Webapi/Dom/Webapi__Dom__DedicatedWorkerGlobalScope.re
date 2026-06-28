type t = Dom.dedicatedWorkerGlobalScope;

include Webapi__Dom__WorkerGlobalScope.Impl({
  type nonrec t = t;
});

[@mel.get] external name: t => string = "name";

[@mel.send.pipe: t] external close: unit = "name";

[@mel.send.pipe: t] external postMessage: 'a => unit = "postMessage";

[@mel.send.pipe: t]
external postMessageWithTransfers: ('a, array(Webapi__Dom__Window.transferable)) => unit =
  "postMessage";
