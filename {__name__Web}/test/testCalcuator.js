/**
 * @File   : testCalcuator.js
 * @Author : {__author__} ({__email})
 * @Link   :
 * @Date   : 2018-4-11 17:45:41
 */

var assert = require("assert");
var calc = require("../src/calc.js");
var objectCal = null;

describe("Calculator Tests", function() {
	beforeEach(function() {
		objectCal = new calc();
	});

	describe("Addition Tests", function() {
		it("returns 1 + 1 = 2", function(done) {
			assert.equal(objectCal.add(1, 1), 2);
			done();
		});

		it("returns 1 + -1 = 0", function(done) {
			assert.equal(objectCal.add(1, -1), 0);
			done();
		});
	});

	describe("Multiplication Tests", function() {
		it("returns 2 * 2 = 4", function(done) {
			assert.equal(objectCal.mul(2, 2), 4);
			done();
		});

		it("returns 0 * 4 = 4", function(done) {
			assert.equal(objectCal.mul(2, 0), 4);
			done();
		});
	});
});
