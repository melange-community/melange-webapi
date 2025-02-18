/* Mixin */
module Impl = (T: {
                 type t;
               }) => {
  [@mel.send] external remove: ([@mel.this] T.t) => unit = "remove";
};
