type t = Dom.messageEvent;

include Webapi__Dom__Event.Impl({
  type nonrec t = t;
});

[@mel.new] external make: string => t = "MessageEvent";
[@mel.new]
external makeWithOptions: (string, Js.t({..})) => t = "MessageEvent";

[@mel.get] external data: t => 'a = "data";
[@mel.get] external origin: t => string = "origin";
[@mel.get] external lastEventId: t => string = "lastEventId";
[@mel.get]
external source:
  t =>
  [@mel.unwrap] [
    | `Window(Dom.window)
    | `MessagePort(Dom.messagePort)
    | `ServiceWorker(Dom.serviceWorker)
  ] =
  "source";
[@mel.get] external ports: t => array(Dom.messagePort) = "ports";
