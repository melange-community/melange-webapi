type t = Dom.shadowRoot;

include NodeRe.Impl({ type nonrec t = t; });
include EventTargetRe.Impl({ type nonrec t = t; });
include NonElementParentNodeRe.Impl({ type nonrec t = t; });
include DocumentOrShadowRootRe.Impl({ });
include ParentNodeRe.Impl({ type nonrec t = t; });

[@bs.get] external shadowRootMode : t => string = "shadowRootMode";
let shadowRootMode: t => DomTypesRe.shadowRootMode =
  (self) => DomTypesRe.decodeShadowRootMode(shadowRootMode(self));
[@bs.get] external host : t => Dom.element = "host";
