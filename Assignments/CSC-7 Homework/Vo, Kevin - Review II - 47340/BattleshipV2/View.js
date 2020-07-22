/* 
    Created on : Sep 18, 2017, 6:28:09 PM
    Author     : Head First Javascript Example Project
 */

 function View(msg, location){
	this.displayMessage();
	this.displayHit();
	this.displayMiss();
	
}

View.prototype.displayMessage = function(msg) {
        var messageArea = document.getElementById("messageArea");
        messageArea.innerHTML = msg;
    };

View.prototype.displayHit = function(location) {
        var cell = document.getElementById(location);
        cell.setAttribute("class", "hit");
    };

View.prototype.displayMiss = function(location) {
        var cell = document.getElementById(location);
        cell.setAttribute("class", "miss");
    };