/**
 * @File   : index.js
 * @Author : Andrew Archer ()
 * @Link   :
 * @Date   : 2018-4-20 18:40:51
 */
"use strict";

import "mustard-ui";
import "./../styles/style.css";
import Icon from "./../images/icon.png";
import printMe from "./print.js";

function component() {
	// Lodash, now imported by this script

	var element = document.createElement("div");
	element.innerHTML = "Hello World ";
	element.classList.add("hello");

	// Add the image to our existing div.
	var myIcon = new Image();
	myIcon.src = Icon;
	element.appendChild(myIcon);

	var btn = document.createElement("button");
	btn.innerHTML = "Click me";
	btn.className = "button-primary";
	btn.onclick = printMe;
	element.appendChild(btn);
	return element;
}
document.getElementById("content").appendChild(component());
//idContent.appendChild(component());
//document.body.appendChild(component());
