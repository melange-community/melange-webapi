module IntersectionObserverEntry = {
  type t = Dom.intersectionObserverEntry;

  [@mel.get] external time: t => float = "time";
  [@mel.get] external rootBounds: t => Dom.domRect = "rootBounds";
  [@mel.get]
  external boundingClientRect: t => Dom.domRect = "boundingClientRect";
  [@mel.get] external intersectionRect: t => Dom.domRect = "intersectionRect";
  [@mel.get] external isIntersecting: t => bool = "isIntersecting";
  [@mel.get] external intersectionRatio: t => float = "intersectionRatio";
  [@mel.get] external target: t => Dom.element = "target";
};

type t = Dom.intersectionObserver;

type intersectionObserverInit = {
  root: option(Dom.element),
  rootMargin: option(string),
  threshold: option(array(float)),
};

[@mel.obj]
external makeInit:
  (
    ~root: Dom.element=?,
    ~rootMargin: string=?,
    ~threshold: array(float)=?,
    unit
  ) =>
  intersectionObserverInit;

[@mel.new]
external make:
  ([@mel.uncurry] ((array(IntersectionObserverEntry.t), t) => unit)) => t =
  "IntersectionObserver";

[@mel.new]
external makeWithInit:
  (
    [@mel.uncurry] ((array(IntersectionObserverEntry.t), t) => unit),
    intersectionObserverInit
  ) =>
  t =
  "IntersectionObserver";

[@mel.get] [@mel.return nullable]
external root: t => option(Dom.element) = "root";
[@mel.get] external rootMargin: t => string = "rootMargin";
[@mel.get] external thresholds: t => array(float) = "thresholds";

[@mel.send] external disconnect: t => unit = "disconnect";
[@mel.send] external observe: (t, Dom.element) => unit = "observe";
[@mel.send] external unobserve: (t, Dom.element) => unit = "unobserve";
[@mel.send]
external takeRecords: t => array(IntersectionObserverEntry.t) = "takeRecords";
