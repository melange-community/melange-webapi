type t = Dom.treeWalker;

[@bs.get] external root : t => Dom.node = "";
[@bs.get] external whatToShow : t => Webapi__Dom__Types.WhatToShow.t = "";
[@bs.get] [@bs.return nullable] external filter : t => option(Dom.nodeFilter) = "";
[@bs.get] external currentNode : t => Dom.node = "";
[@bs.set] external setCurrentNode : (t, Dom.node) => unit = "";

[@bs.send.pipe : t] [@bs.return nullable] external parentNode : option(Dom.node) = "parentNode";
[@bs.send.pipe : t] [@bs.return nullable] external firstChild : option(Dom.node) = "firstChild";
[@bs.send.pipe : t] [@bs.return nullable] external lastChild : option(Dom.node) = "lastChild";
[@bs.send.pipe : t] [@bs.return nullable] external previousSibling : option(Dom.node) = "previousSibling";
[@bs.send.pipe : t] [@bs.return nullable] external nextSibling : option(Dom.node) = "nextSibling";
[@bs.send.pipe : t] [@bs.return nullable] external previousNode : option(Dom.node) = "previousNode";
[@bs.send.pipe : t] [@bs.return nullable] external nextNode : option(Dom.node) = "nextNode";
