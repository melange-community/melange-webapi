type t = Dom.workerGlobalScope;

module Impl = (T: {
                 type t;
               }) => {
  [@mel.get] external self: T.t => T.t = "self";

  [@mel.send.pipe: T.t]
  external addErrorEventListener:
    ([@mel.as "error"] _, Dom.messageEvent => unit) => unit =
    "addEventListener";

  [@mel.send.pipe: T.t]
  external removeErrorEventListener:
    ([@mel.as "error"] _, Dom.messageEvent => unit) => unit =
    "removeEventListener";

  [@mel.send.pipe: T.t]
  external addMessageEventListener:
    ([@mel.as "message"] _, Dom.messageEvent => unit) => unit =
    "addEventListener";

  [@mel.send.pipe: T.t]
  external removeMessageEventListener:
    ([@mel.as "message"] _, Dom.messageEvent => unit) => unit =
    "removeEventListener";

  [@mel.send.pipe: T.t]
  external addMessageErrorEventListener:
    ([@mel.as "messageerror"] _, Dom.messageEvent => unit) => unit =
    "addEventListener";

  [@mel.send.pipe: T.t]
  external removeMessageErrorEventListener:
    ([@mel.as "messageerror"] _, Dom.messageEvent => unit) => unit =
    "removeEventListener";
};

include Webapi__Dom__EventTarget.Impl({
  type nonrec t = t;
});
