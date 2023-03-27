//"beoww" going down in tone 

let osctwo, osc, playing, freq, amp;
let arr = [130, 240, 430, 190, 297];
let arrtwo = [100, 100, 250, 500, 500];

function setup() {
  let cnv = createCanvas(400, 400);
  cnv.mousePressed(playOscillator);
  osc = new p5.Oscillator('sine');
  osctwo = new p5.Oscillator('triangle');
}

function draw() {
  background(220)
  freq = constrain(map(mouseX, 0, width, 100, 500), 100, 500);
  amp = constrain(map(mouseY, height, 0, 0, 1), 0, 1); //gonna use the coords w/ vis

  text('tap to play', 20, 20);
  text('freq: ' + freq, 20, 40);
  text('amp: ' + amp, 20, 60);

  if (playing) {
    // smooth the transitions by 0.1 seconds
    for(let i=0; i<arr.length; i++){
    osc.freq(arr[i], 0.5);
    osctwo.freq(arrtwo[i], 1);
    }
    osctwo.amp(amp, 0.5);
    osc.amp(amp, 0.5);
  }
}

function playOscillator() {
  // starting an oscillator on a user gesture will enable audio
  // in browsers that have a strict autoplay policy.
  // See also: userStartAudio();
  osc.start();
  osctwo.start();
  playing = true;
}

function mouseReleased() {
  // ramp amplitude to 0 over 0.5 seconds
  osc.amp(0, 0.5);
  osctwo.amp(0, 0.5);
  playing = false;
}