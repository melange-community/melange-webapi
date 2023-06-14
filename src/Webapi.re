type rafId;

[@bs.val] external requestAnimationFrame : (float => unit) => unit = "requestAnimationFrame";
[@bs.val] external requestCancellableAnimationFrame : (float => unit) => rafId = "requestAnimationFrame";
[@bs.val] external cancelAnimationFrame : rafId => unit = "cancelAnimationFrame";

module Base64 = Base64Re;
module Canvas = CanvasRe;
module Dom = DomRe;

module File = {
  include FileRe;
  [@deprecated "Use `Webapi.Url` instead"] module Url = UrlRe;
};

module UrlSearchParams = URLSearchParamsRe;
module Url = UrlRe;
