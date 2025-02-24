type t = Dom.nodeIterator;

[@mel.get] external root: t => Dom.node = "root";
[@mel.get] external referenceNode: t => Dom.node = "referenceNode";
[@mel.get]
external pointerBeforeReferenceNode: t => bool = "pointerBeforeReferenceNode";
[@mel.get]
external whatToShow: t => Webapi__Dom__Types.WhatToShow.t = "whatToShow";
[@mel.get] [@mel.return nullable]
external filter: t => option(Dom.nodeFilter) = "filter";

[@mel.send] [@mel.return nullable]
external nextNode: ([@mel.this] t) => option(Dom.node) = "nextNode";
[@mel.send] [@mel.return nullable]
external previousNode: ([@mel.this] t) => option(Dom.node) = "previousNode";
[@mel.send] external detach: ([@mel.this] t) => unit = "detach";
