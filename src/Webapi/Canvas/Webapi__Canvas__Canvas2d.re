type t; /* Main type, representing the 2d canvas rendering context object */
type gradient;
type pattern;
type measureText;

/* Sub-modules (and their interfaces) for string enum arguments: */
module type CompositeType = {
  type t = pri string;

  let sourceOver: t;
  let sourceIn: t;
  let sourceOut: t;
  let sourceAtop: t;
  let destinationOver: t;
  let destinationIn: t;
  let destinationOut: t;
  let destinationAtop: t;
  let lighter: t;
  let copy: t;
  let xor: t;
};

module Composite: CompositeType = {
  type t = string;

  let sourceOver: t = "source-over";
  let sourceIn: t = "source-in";
  let sourceOut: t = "source-out";
  let sourceAtop: t = "source-atop";
  let destinationOver: t = "destination-over";
  let destinationIn: t = "destination-in";
  let destinationOut: t = "destination-out";
  let destinationAtop: t = "destination-atop";
  let lighter: t = "lighter";
  let copy: t = "copy";
  let xor: t = "xor";
};

module type LineCapType = {
  type t = pri string;

  let butt: t;
  let round: t;
  let square: t;
};

module LineCap: LineCapType = {
  type t = string;

  let butt: t = "butt";
  let round: t = "round";
  let square: t = "square";
};

module type LineJoinType = {
  type t = pri string;

  let round: t;
  let bevel: t;
  let miter: t;
};

module LineJoin: LineJoinType = {
  type t = string;

  let round: t = "round";
  let bevel: t = "bevel";
  let miter: t = "miter";
};

type image('a) =
  | Number: image(float)
  | ImageData: image(Webapi__Dom__Image.t);

type style(_) =
  | String: style(string)
  | Gradient: style(gradient)
  | Pattern: style(pattern);

/* 2d Canvas API, following https://simon.html5.org/dump/html5-canvas-cheat-sheet.html */
[@mel.send] external save: ([@mel.this] t) => unit = "save";
[@mel.send] external restore: ([@mel.this] t) => unit = "restore";

/* Transformation */
[@mel.send]
external scale: (~x: float, ~y: float, [@mel.this] t) => unit = "scale";
[@mel.send] external rotate: (float, [@mel.this] t) => unit = "rotate";
[@mel.send]
external translate: (~x: float, ~y: float, [@mel.this] t) => unit =
  "translate";
[@mel.send]
external transform:
  (
    ~m11: float,
    ~m12: float,
    ~m21: float,
    ~m22: float,
    ~dx: float,
    ~dy: float,
    [@mel.this] t
  ) =>
  unit =
  "transform";
[@mel.send]
external setTransform:
  (
    ~m11: float,
    ~m12: float,
    ~m21: float,
    ~m22: float,
    ~dx: float,
    ~dy: float,
    [@mel.this] t
  ) =>
  unit =
  "setTransform";

/* Compositing */
[@mel.set] external globalAlpha: (t, float) => unit = "globalAlpha";
[@mel.set]
external globalCompositeOperation: (t, Composite.t) => unit =
  "globalCompositeOperation";

/* Line Styles */
[@mel.set] external lineWidth: (t, float) => unit = "lineWidth";
[@mel.set] external lineCap: (t, LineCap.t) => unit = "lineCap";
[@mel.set] external lineJoin: (t, LineJoin.t) => unit = "lineJoin";
[@mel.set] external miterLimit: (t, float) => unit = "miterLimit";

/* Colors, Styles, and Shadows */
[@mel.set] external setFillStyle: (t, 'a) => unit = "fillStyle";
[@mel.set] external setStrokeStyle: (t, 'a) => unit = "strokeStyle";

/* in re unused warnings
   awaiting release of https://github.com/bloomberg/bucklescript/issues/1656
   to just use [@@mel.set] directly with an ignored (style a) */
let setStrokeStyle = (type a, ctx: t, _: style(a), v: a) =>
  setStrokeStyle(ctx, v);

let setFillStyle = (type a, ctx: t, _: style(a), v: a) =>
  setFillStyle(ctx, v);

let reifyStyle = (type a, x: 'a): (style(a), a) => {
  module Internal = {
    type constructor;
    external canvasGradient: constructor = "CanvasGradient"; /* internal */
    external canvasPattern: constructor = "CanvasPattern"; /* internal */
    let instanceOf: ('a, constructor) => bool = [%mel.raw
      {|function(x,y) {return +(x instanceof y)}|}
    ]; /* internal */
  };

  (
    if (Js.typeof(x) == "string") {
      Obj.magic(String);
    } else if (Internal.instanceOf(x, Internal.canvasGradient)) {
      Obj.magic(Gradient);
    } else if (Internal.instanceOf(x, Internal.canvasPattern)) {
      Obj.magic(Pattern);
    } else {
      raise(
        Invalid_argument(
          "Unknown canvas style kind. Known values are: String, CanvasGradient, CanvasPattern",
        ),
      );
    },
    Obj.magic(x),
  );
};

[@mel.get] external fillStyle: t => 'a = "fillStyle";
[@mel.get] external strokeStyle: t => 'a = "strokeStyle";

let fillStyle = (ctx: t) => ctx |> fillStyle |> reifyStyle;

let strokeStyle = (ctx: t) => ctx |> strokeStyle |> reifyStyle;

[@mel.set] external shadowOffsetX: (t, float) => unit = "shadowOffsetX";
[@mel.set] external shadowOffsetY: (t, float) => unit = "shadowOffsetY";
[@mel.set] external shadowBlur: (t, float) => unit = "shadowBlur";
[@mel.set] external shadowColor: (t, string) => unit = "shadowColor";

/* Gradients */
[@mel.send]
external createLinearGradient:
  (~x0: float, ~y0: float, ~x1: float, ~y1: float, [@mel.this] t) => gradient =
  "createLinearGradient";
[@mel.send]
external createRadialGradient:
  (
    ~x0: float,
    ~y0: float,
    ~x1: float,
    ~y1: float,
    ~r0: float,
    ~r1: float,
    [@mel.this] t
  ) =>
  gradient =
  "createRadialGradient";
[@mel.send]
external addColorStop: (float, string, [@mel.this] gradient) => unit =
  "addColorStop";

external createPattern:
  (
    t,
    Dom.element,
    [@mel.string] [
      | `repeat
      | [@mel.as "repeat-x"] `repeatX
      | [@mel.as "repeat-y"] `repeatY
      | [@mel.as "no-repeat"] `noRepeat
    ]
  ) =>
  pattern =
  "createPattern";

/* Paths */
[@mel.send] external beginPath: ([@mel.this] t) => unit = "beginPath";
[@mel.send] external closePath: ([@mel.this] t) => unit = "closePath";
[@mel.send] external fill: ([@mel.this] t) => unit = "fill";
[@mel.send] external stroke: ([@mel.this] t) => unit = "stroke";
[@mel.send] external clip: ([@mel.this] t) => unit = "clip";
[@mel.send]
external moveTo: (~x: float, ~y: float, [@mel.this] t) => unit = "moveTo";
[@mel.send]
external lineTo: (~x: float, ~y: float, [@mel.this] t) => unit = "lineTo";
[@mel.send]
external quadraticCurveTo:
  (~cp1x: float, ~cp1y: float, ~x: float, ~y: float, [@mel.this] t) => unit =
  "quadraticCurveTo";
[@mel.send]
external bezierCurveTo:
  (
    ~cp1x: float,
    ~cp1y: float,
    ~cp2x: float,
    ~cp2y: float,
    ~x: float,
    ~y: float,
    [@mel.this] t
  ) =>
  unit =
  "bezierCurveTo";
[@mel.send]
external arcTo:
  (~x1: float, ~y1: float, ~x2: float, ~y2: float, ~r: float, [@mel.this] t) =>
  unit =
  "arcTo";
[@mel.send]
external arc:
  (
    ~x: float,
    ~y: float,
    ~r: float,
    ~startAngle: float,
    ~endAngle: float,
    ~anticw: bool,
    [@mel.this] t
  ) =>
  unit =
  "arc";
[@mel.send]
external rect:
  (~x: float, ~y: float, ~w: float, ~h: float, [@mel.this] t) => unit =
  "rect";
[@mel.send]
external isPointInPath: (~x: float, ~y: float, [@mel.this] t) => bool =
  "isPointInPath";

/* Text */
[@mel.set] external font: (t, string) => unit = "font";
[@mel.set] external textAlign: (t, string) => unit = "textAlign";
[@mel.set] external textBaseline: (t, string) => unit = "textBaseline";
[@mel.send]
external fillText:
  (string, ~x: float, ~y: float, ~maxWidth: float=?, [@mel.this] t) => unit =
  "fillText";
[@mel.send]
external strokeText:
  (string, ~x: float, ~y: float, ~maxWidth: float=?, [@mel.this] t) => unit =
  "strokeText";
[@mel.send]
external measureText: (string, [@mel.this] t) => measureText = "measureText";
[@mel.get] external width: measureText => float = "width";

/* Rectangles */
[@mel.send]
external fillRect:
  (~x: float, ~y: float, ~w: float, ~h: float, [@mel.this] t) => unit =
  "fillRect";
[@mel.send]
external strokeRect:
  (~x: float, ~y: float, ~w: float, ~h: float, [@mel.this] t) => unit =
  "strokeRect";
[@mel.send]
external clearRect:
  (~x: float, ~y: float, ~w: float, ~h: float, [@mel.this] t) => unit =
  "clearRect";

[@mel.send]
external createImageDataCoords:
  (t, ~width: float, ~height: float) => Webapi__Dom__Image.t =
  "createImageData";
[@mel.send]
external createImageDataFromImage:
  (t, Webapi__Dom__Image.t) => Webapi__Dom__Image.t =
  "createImageData";

[@mel.send]
external getImageData:
  (t, ~sx: float, ~sy: float, ~sw: float, ~sh: float) => Webapi__Dom__Image.t =
  "getImageData";

[@mel.send]
external putImageData:
  (t, ~imageData: Webapi__Dom__Image.t, ~dx: float, ~dy: float) => unit =
  "putImageData";

[@mel.send]
external putImageDataWithDirtyRect:
  (
    t,
    ~imageData: Webapi__Dom__Image.t,
    ~dx: float,
    ~dy: float,
    ~dirtyX: float,
    ~dirtyY: float,
    ~dirtyWidth: float,
    ~dirtyHeight: float
  ) =>
  unit =
  "putImageData";
