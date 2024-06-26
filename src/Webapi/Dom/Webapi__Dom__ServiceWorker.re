type t = Dom.serviceWorker;

include Webapi__Dom__EventTarget.Impl({
  type nonrec t = t;
});

[@mel.get] external scriptURL: t => string = "scriptURL";
[@mel.get] external state: t => string = "";
