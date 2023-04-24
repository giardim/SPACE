class Vector1D {
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
    rectMode(CORNERS);
    textAlign(CENTER, BOTTOM);
    for (let i = 0; i < this.data.data[this.step].length; i++) {
      const D = this.data.data[this.step][i];
      const X0 = (i + 0.0) * width / this.data.data[this.step].length;
      const Y0 = map(0, this.min, this.max, height, 0);
      const X1 = (i + 1.0) * width / this.data.data[this.step].length;
      const Y1 = map(D, this.min, this.max, height, 0);
      if (this.data.indices[this.step].some(index => index == i)) {
        fill(theme.sbg); stroke(theme.bg);
      } else {
        fill(theme.fg); stroke(theme.bg);
      }
      rect(X0, Y0, X1, Y1);
    }
    for (let i = 0; i < this.data.data[this.step].length; i++) {
      const D = this.data.data[this.step][i];
      const X0 = (i + 0.0) * width / this.data.data[this.step].length;
      const Y0 = map(0, this.min, this.max, height, 0);
      const X1 = (i + 1.0) * width / this.data.data[this.step].length;
      const Y1 = map(D, this.min, this.max, height, 0);
      if (
        (X0 <= mouseX && mouseX <= X1 || X1 <= mouseX && mouseX <= X0) &&
        (Y0 <= mouseY && mouseY <= Y1 || Y1 <= mouseY && mouseY <= Y0)
      ) {
        if (this.data.indices[this.step].some(index => index == i)) {
          fill(theme.fg); stroke(theme.sfg);
        } else {
          fill(theme.sbg); stroke(theme.sfg);
        }
        text(this.data.is_char ? String.fromCodePoint(D) : D, mouseX, mouseY);
      }
    }
  }

  table() {
    rectMode(CENTER);
    textAlign(CENTER, CENTER);
    for (let i = 0; i < this.data.data[this.step].length; i++) {
      const D = this.data.data[this.step][i];
      const X = (i + 0.5) * width / this.data.data[this.step].length;
      const Y = height / 2;
      const S = width / this.data.data[this.step].length;
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
