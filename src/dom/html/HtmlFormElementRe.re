/*
 * Spec: https://html.spec.whatwg.org/multipage/forms.html#the-form-element
 * MDN: https://developer.mozilla.org/en-US/docs/Web/API/HTMLFormElement
 */

module Impl = (T: {type t;}) => {
  type t_htmlFormElement = T.t;

  /* TODO: elements: HTMLFormControlsCollection */
  [@bs.get] external length : t_htmlFormElement => int = "length";
  [@bs.get] external name : t_htmlFormElement => string = "name";
  [@bs.set] external setName : (t_htmlFormElement, string) => unit = "name";
  [@bs.get] external method : t_htmlFormElement => string = "method";
  [@bs.set] external setMethod : (t_htmlFormElement, string) => unit = "method";
  [@bs.get] external target : t_htmlFormElement => string = "target";
  [@bs.set] external setTarget : (t_htmlFormElement, string) => unit = "target";
  [@bs.get] external action : t_htmlFormElement => string = "action";
  [@bs.set] external setAction : (t_htmlFormElement, string) => unit = "action";
  [@bs.get] external acceptCharset : t_htmlFormElement => string = "acceptCharset";
  [@bs.set] external setAcceptCharset : (t_htmlFormElement, string) => unit = "acceptCharset";
  [@bs.get] external autocomplete : t_htmlFormElement => string = "autocomplete";
  [@bs.set] external setAutocomplete : (t_htmlFormElement, string) => unit = "autocomplete";
  [@bs.get] external noValidate : t_htmlFormElement => bool = "noValidate";
  [@bs.set] external setNoValidate : (t_htmlFormElement, bool) => unit = "noValidate";
  [@bs.get] external enctype : t_htmlFormElement => string = "enctype";
  [@bs.set] external setEnctype : (t_htmlFormElement, string) => unit = "enctype";
  [@bs.get] external encoding : t_htmlFormElement => string = "encoding";
  [@bs.set] external setEncoding : (t_htmlFormElement, string) => unit = "encoding";

  [@bs.send.pipe: t_htmlFormElement] external submit : unit = "submit";
  [@bs.send.pipe: t_htmlFormElement] external reset : unit = "reset";
  [@bs.send.pipe: t_htmlFormElement] external checkValidity : bool = "checkValidity";
  [@bs.send.pipe: t_htmlFormElement] external reportValidity : bool = "reportValidity";
};

type t = Dom.htmlFormElement;

include EventTargetRe.Impl({ type nonrec t = t; });
include NodeRe.Impl({ type nonrec t = t; });
include ElementRe.Impl({ type nonrec t = t; });
include HtmlElementRe.Impl({ type nonrec t = t; });
include Impl({ type nonrec t = t; });
