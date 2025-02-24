type t = Dom.treeWalker;

[@mel.get] external root: t => Dom.node = "root";
[@mel.get]
external whatToShow: t => Webapi__Dom__Types.WhatToShow.t = "whatToShow";
[@mel.get] [@mel.return nullable]
external filter: t => option(Dom.nodeFilter) = "filter";
[@mel.get] external currentNode: t => Dom.node = "currentNode";
[@mel.set] external setCurrentNode: (t, Dom.node) => unit = "setCurrentNode";

[@mel.send] [@mel.return nullable]
external parentNode: ([@mel.this] t) => option(Dom.node) = "parentNode";
[@mel.send] [@mel.return nullable]
external firstChild: ([@mel.this] t) => option(Dom.node) = "firstChild";
[@mel.send] [@mel.return nullable]
external lastChild: ([@mel.this] t) => option(Dom.node) = "lastChild";
[@mel.send] [@mel.return nullable]
external previousSibling: ([@mel.this] t) => option(Dom.node) =
  "previousSibling";
[@mel.send] [@mel.return nullable]
external nextSibling: ([@mel.this] t) => option(Dom.node) = "nextSibling";
[@mel.send] [@mel.return nullable]
external previousNode: ([@mel.this] t) => option(Dom.node) = "previousNode";
[@mel.send] [@mel.return nullable]
external nextNode: ([@mel.this] t) => option(Dom.node) = "nextNode";
