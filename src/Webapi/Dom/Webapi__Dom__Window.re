type console; /* Console API, should maybe be defined in Js stdlib */
type crypto; /* Web Cryptography API */
type frameList; /* array-like, WindowProxy? */
type idleDeadline; /* Cooperative Scheduling of Background Tasks */
type locationbar; /* "bar object" */
type menubar; /* "bar object" */
type navigator;
type personalbar; /* "bar object" */
type screen;
type scrollbars; /* "bar object" */
type speechSynthesis;
type statusbar; /* "bar object" */
type toolbar; /* "bar object" */
type mediaQueryList; /* CSSOM View module */
type transferable;

type idleCallbackId; /* used by requestIdleCallback and cancelIdleCallback */

module Impl = (T: {
                 type t;
               }) => {
  type t_window = T.t;

  /* A lot of this isn't really "dom", but rather global exports */

  [@mel.get] external console: t_window => console = "console";
  [@mel.get] external crypto: t_window => crypto = "crypto";
  [@mel.get] external document: t_window => Dom.document = "document";
  [@mel.get] [@mel.return nullable]
  external frameElement: t_window => option(Dom.element) = "frameElement"; /* experimental? */
  [@mel.get] external frames: t_window => frameList = "frames";
  [@mel.get] external fullScreen: t_window => bool = "fullScreen";
  [@mel.get] external history: t_window => Dom.history = "history";
  [@mel.get] external innerWidth: t_window => int = "innerWidth";
  [@mel.get] external innerHeight: t_window => int = "innerHeight";
  [@mel.get] external isSecureContext: t_window => bool = "isSecureContext";
  [@mel.get] external length: t_window => int = "length";
  [@mel.get] external location: t_window => Dom.location = "location";
  [@mel.set] external setLocation: (t_window, string) => unit = "location";
  [@mel.get] external locationbar: t_window => locationbar = "locationbar";
  /* localStorage: accessed directly via Dom.Storage.localStorage */
  [@mel.get] external menubar: t_window => menubar = "menubar";
  [@mel.get] external name: t_window => string = "name";
  [@mel.set] external setName: (t_window, string) => unit = "name";
  [@mel.get] external navigator: t_window => navigator = "navigator";
  [@mel.get] [@mel.return nullable]
  external opener: t_window => option(Dom.window) = "opener";
  [@mel.get] external outerWidth: t_window => int = "outerWidth";
  [@mel.get] external outerHeight: t_window => int = "outerHeight";
  [@mel.get] external pageXOffset: t_window => float = "pageXOffset"; /* alias for scrollX */
  [@mel.get] external pageYOffset: t_window => float = "pageYOffset"; /* alias for scrollY */
  [@mel.get] external parent: t_window => Dom.window = "parent";
  [@mel.get]
  external performance: t_window => Webapi__Performance.t = "performance";
  [@mel.get] external personalbar: t_window => personalbar = "personalbar";
  [@mel.get] external screen: t_window => screen = "screen";
  [@mel.get] external screenX: t_window => int = "screenX";
  [@mel.get] external screenY: t_window => int = "screenY";
  [@mel.get] external scrollbars: t_window => scrollbars = "scrollbars";
  [@mel.get] external scrollX: t_window => float = "scrollX";
  [@mel.get] external scrollY: t_window => float = "scrollY";
  [@mel.get] external self: t_window => Dom.window = "self"; /* alias for window, but apparently convenient because self (stand-alone) resolves to WorkerGlobalScope in a web worker. Probably poitnless here though */
  /* sessionStorage: accessed directly via Dom.Storage.sessionStorage */
  [@mel.get]
  external speechSynthesis: t_window => speechSynthesis = "speechSynthesis"; /* experimental */
  [@mel.get] external status: t_window => string = "status";
  [@mel.set] external setStatus: (t_window, string) => unit = "status";
  [@mel.get] external statusbar: t_window => statusbar = "statusbar";
  [@mel.get] external toolbar: t_window => toolbar = "toolbar";
  [@mel.get] external top: t_window => Dom.window = "top";
  [@mel.get] external window: t_window => t_window = "window"; /* This is pointless I think, it's just here because window is the implicit global scope, and it's needed to be able to get a reference to it */

  [@mel.send] external alert: (string, [@mel.this] t_window) => unit = "alert";
  [@mel.send] external blur: ([@mel.this] t_window) => unit = "blur";

  /* experimental, Cooperative Scheduling of Background Tasks */
  [@mel.send]
  external cancelIdleCallback: (idleCallbackId, [@mel.this] t_window) => unit =
    "cancelIdleCallback";

  [@mel.send] external close: ([@mel.this] t_window) => unit = "close";
  [@mel.send]
  external confirm: (string, [@mel.this] t_window) => bool = "confirm";
  [@mel.send] external focus: ([@mel.this] t_window) => unit = "focus";
  [@mel.send]
  external getComputedStyle:
    (Dom.element, [@mel.this] t_window) => Dom.cssStyleDeclaration =
    "getComputedStyle";
  [@mel.send]
  external getComputedStyleWithPseudoElement:
    (Dom.element, string, [@mel.this] t_window) => Dom.cssStyleDeclaration =
    "getComputedStyle";
  [@mel.send]
  external getSelection: ([@mel.this] t_window) => Dom.selection =
    "getSelection";
  [@mel.send]
  external matchMedia: (string, [@mel.this] t_window) => mediaQueryList =
    "matchMedia"; /* experimental, CSSOM View module */

  /* experimental, CSSOM View module */
  [@mel.send]
  external moveBy: (int, int, [@mel.this] t_window) => unit = "moveBy";

  /* experimental, CSSOM View module */
  [@mel.send]
  external moveTo: (int, int, [@mel.this] t_window) => unit = "moveTo";

  /* yes, features is a stringly typed list of key value pairs, sigh */
  [@mel.send] [@mel.return nullable]
  external open_:
    (~url: string, ~name: string, ~features: string=?, [@mel.this] t_window) =>
    option(Dom.window) =
    "open";

  [@mel.send]
  external postMessage: ('a, string, [@mel.this] t_window) => unit =
    "postMessage"; /* experimental-ish?, Web Messaging */
  [@mel.send]
  external postMessageWithTransfers:
    ('a, string, array(transferable), [@mel.this] t_window) => unit =
    "postMessage"; /* experimental-ish?, Web Messaging */
  [@mel.send] external print: ([@mel.this] t_window) => unit = "print";
  [@mel.send]
  external prompt: (string, [@mel.this] t_window) => string = "prompt";
  [@mel.send]
  external promptWithDefault: (string, string, [@mel.this] t_window) => string =
    "prompt";
  /* requestAnimationFrame: accessed directly via Webapi */
  [@mel.send]
  external requestIdleCallback:
    (idleDeadline => unit, [@mel.this] t_window) => idleCallbackId =
    "requestIdleCallback"; /* experimental, Cooperative Scheduling of Background Tasks */
  [@mel.send]
  external requestIdleCallbackWithOptions:
    (idleDeadline => unit, {. "timeout": int}, [@mel.this] t_window) =>
    idleCallbackId =
    "requestIdleCallback"; /* experimental, Cooperative Scheduling of Background Tasks */
  [@mel.send]
  external resizeBy: (int, int, [@mel.this] t_window) => unit = "resizeBy"; /* experimental, CSSOM View module */
  [@mel.send]
  external resizeTo: (int, int, [@mel.this] t_window) => unit = "resizeTo"; /* experimental, CSSOM View module */
  [@mel.send]
  external scroll: (float, float, [@mel.this] t_window) => unit = "scroll"; /* experimental, CSSOM View module */
  [@mel.send]
  external scrollBy: (float, float, [@mel.this] t_window) => unit = "scrollBy"; /* experimental, CSSOM View module */
  [@mel.send]
  external scrollTo: (float, float, [@mel.this] t_window) => unit = "scrollTo"; /* experimental, CSSOM View module */
  [@mel.send] external stop: ([@mel.this] t_window) => unit = "stop";

  [@mel.send]
  external addPopStateEventListener:
    (
      [@mel.as "popstate"] _,
      Dom.popStateEvent => unit,
      [@mel.this] t_window
    ) =>
    unit =
    "addEventListener";
  [@mel.send]
  external removePopStateEventListener:
    (
      [@mel.as "popstate"] _,
      Dom.popStateEvent => unit,
      [@mel.this] t_window
    ) =>
    unit =
    "removeEventListener";

  [@mel.set] external setOnLoad: (t_window, unit => unit) => unit = "onload"; /* use addEventListener instead? */
};

type t = Dom.window;

/* include WindowOrWorkerGlobalScope? not really "dom" though */
include Webapi__Dom__EventTarget.Impl({
  type nonrec t = t;
});
include Webapi__Dom__GlobalEventHandlers.Impl({
  type nonrec t = t;
});
include Impl({
  type nonrec t = t;
});
