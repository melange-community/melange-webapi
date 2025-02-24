/* Mixin */
module Impl = (T: {
                 type t;
               }) => {
  [@mel.send] [@mel.return nullable]
  external getElementById: (string, [@mel.this] T.t) => option(Dom.element) =
    "getElementById";
};
