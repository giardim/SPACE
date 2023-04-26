class Stack {
  constructor(data) {
    this.data = data;
    this.step = 0;
    this.min = min(min(this.data.data[this.step]), 0);
    this.max = max(max(this.data.data[this.step]), 0);
  }

  getStep() {
    return this.step;
  }

  setStep(step) {
    this.step = constrain(step | 0, 0, this.data.data.length - 1);
    this.min = min(min(this.data.data[this.step]), 0);
    this.max = max(max(this.data.data[this.step]), 0);
    $('#step').val(this.step.toString().padStart((this.data.data.length - 1).toString().length, 0));
    $('#step-slider').val(this.step);
    return 0 < this.step && this.step < this.data.data.length - 1;
  }

  prev() {
    return this.setStep(this.getStep() - 1);
  }

  next() {
    return this.setStep(this.getStep() + 1);
  }

  graph() {
    rectMode(CENTER);
    textAlign(CENTER, BOTTOM);
    for (let i = 0; i < this.data.data[this.step].length; i++) {
      const D = this.data.data[this.step][i];
      const X = width / 2;
      const Y = (i + 0.5) * height / this.data.data[this.step].length;
      const W = map(D, this.min, this.max, 0, width);
      const H = height / this.data.data[this.step].length;
      fill(theme.fg); stroke(theme.bg);
      rect(X, Y, W, H);
    }
    for (let i = 0; i < this.data.data[this.step].length; i++) {
      const D = this.data.data[this.step][i];
      const X = width / 2;
      const Y = (i + 0.5) * height / this.data.data[this.step].length;
      const W = map(D, this.min, this.max, 0, width);
      const H = height / this.data.data[this.step].length;
      const X0 = X - W / 2;
      const Y0 = Y - H / 2;
      const X1 = X + W / 2;
      const Y1 = Y + H / 2;
      if (
        (X0 <= mouseX && mouseX <= X1 || X1 <= mouseX && mouseX <= X0) &&
        (Y0 <= mouseY && mouseY <= Y1 || Y1 <= mouseY && mouseY <= Y0)
      ) {
        fill(theme.sbg); stroke(theme.sfg);
        text(this.data.is_char ? String.fromCodePoint(D) : D, mouseX, mouseY);
      }
    }
  }

  table() {
    rectMode(CENTER);
    textAlign(CENTER, CENTER);
    const data = [0, ...this.data.data[this.step]];
    if (this.step) {
      if (this.data.data[this.step - 1].length < this.data.data[this.step].length) {
        data[0] = svg.arrowr;
      }
      if (this.data.data[this.step - 1].length > this.data.data[this.step].length) {
        data[0] = svg.arrowl;
      }
      const D = data[0];
      const X = (0 + 0.5) * width / data.length;
      const Y = height / 2;
      const S = width / data.length;
      fill(theme.sbg); stroke(theme.bg);
      square(X, Y, S);
      fill(theme.fg); stroke(theme.sfg);
      push();
      translate(0, height / 2);
      scale(S / D.w);
      translate(-D.x, - D.y - D.h / 2);
      $('canvas')[0].getContext('2d').fill(D.path);
      pop();
    }
    for (let i = 1; i < data.length; i++) {
      const D = data[i];
      const X = (i + 0.5) * width / data.length;
      const Y = height / 2;
      const S = width / data.length;
      if (this.data.indices[this.step].some(index => index == i)) {
        fill(theme.sbg); stroke(theme.bg);
        square(X, Y, S);
        fill(theme.fg); stroke(theme.sfg);
        text(this.data.is_char ? String.fromCodePoint(D) : D, X, Y);
      } else {
        fill(theme.fg); stroke(theme.bg);
        square(X, Y, S);
        fill(theme.sbg); stroke(theme.sfg);
        text(this.data.is_char ? String.fromCodePoint(D) : D, X, Y);
      }
    }
  }
}
