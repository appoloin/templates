/**
 * @File   : calc.js
 * @Author : {__author__} ({__email})
 * @Link   :
 * @Date   : 2018-4-11 18:23:42
 */

"use strict";

function calculator() {}

calculator.prototype = {
	add: function(i, j) {
		return i + j;
	},

	mul: function(i, j) {
		return i * j;
	}
};

// If we're running under Node,
if (typeof exports !== "undefined") {
	module.exports = calculator;
}
