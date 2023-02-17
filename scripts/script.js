function setup() {
  createCanvas(windowWidth * 0.75, windowHeight);
  $('#canvas').append($('canvas'));
  $('main').remove();
}

function draw() {
  background(0);
}

function windowResized() {
  resizeCanvas(windowWidth * 0.75, windowHeight);
}
