type t = Dom.messageChannel;

[@mel.new] external make: unit => t = "MessageChannel";
[@mel.get] external port1: t => Webapi__Dom__MessagePort.t = "port1";
[@mel.get] external port2: t => Webapi__Dom__MessagePort.t = "port2";
