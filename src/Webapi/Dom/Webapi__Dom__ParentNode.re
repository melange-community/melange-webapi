/* Mixin */
module Impl = (T: {
                 type t;
               }) => {
  [@mel.get] external children: T.t => Dom.htmlCollection = "children";
  [@mel.get] [@mel.return nullable]
  external firstElementChild: T.t => option(Dom.element) =
    "firstElementChild";
  [@mel.get] [@mel.return nullable]
  external lastElementChild: T.t => option(Dom.element) = "lastElementChild";
  [@mel.get] external childElementCount: T.t => int = "childElementCount";
  [@mel.send] [@mel.return nullable]
  external querySelector: (string, [@mel.this] T.t) => option(Dom.element) =
    "querySelector";
  [@mel.send]
  external querySelectorAll: (string, [@mel.this] T.t) => Dom.nodeList =
    "querySelectorAll";
};
