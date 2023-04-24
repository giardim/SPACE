class Vector2D {
  constructor(data) {
    this.data = data;
    this.step = 0;
    this.min = +Infinity;
    this.max = -Infinity;
    for (let r = 0; r < this.data.data[this.step].length; r++) {
      this.min = min(min(min(this.data.data[this.step][r]), this.min), 0);
      this.max = max(max(max(this.data.data[this.step][r]), this.max), 0);
    }
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
    rectMode(CENTER);
    textAlign(CENTER, BOTTOM);
    for (let r = 0; r < this.data.data[this.step].length; r++) {
      for (let c = 0; c < this.data.data[this.step][r].length; c++) {
        const D = this.data.data[this.step][r][c];
        const R = this.data.data[this.step].length;
        const C = this.data.data[this.step][r].length;
        const W = width / C;
        const H = height / R;
        const S = min(W, H);
        const X = (c + 0.5 - R / 2) * S + width / 2;
        const Y = (r + 0.5 - C / 2) * S + height / 2;
        if (this.data.indices[this.step].some(index => index[0] == r && index[1] == c)) {
          fill(lerpColor(color(theme.sfg), color(theme.sbg), map(D, this.min, this.max, 0, 1))); stroke(theme.bg);
        } else {
          fill(lerpColor(color(theme.bg), color(theme.fg), map(D, this.min, this.max, 0, 1))); stroke(theme.bg);
        }
        square(X, Y, S);
      }
    }
    for (let r = 0; r < this.data.data[this.step].length; r++) {
      for (let c = 0; c < this.data.data[this.step][r].length; c++) {
        const D = this.data.data[this.step][r][c];
        const R = this.data.data[this.step].length;
        const C = this.data.data[this.step][r].length;
        const W = width / C;
        const H = height / R;
        const S = min(W, H);
        const X = (c + 0.5 - R / 2) * S + width / 2;
        const Y = (r + 0.5 - C / 2) * S + height / 2;
        if (
          X - S / 2 <= mouseX && mouseX <= X + S / 2 &&
          Y - S / 2 <= mouseY && mouseY <= Y + S / 2
        ) {
          if (this.data.indices[this.step].some(index => index[0] == r && index[1] == c)) {
            fill(lerpColor(color(theme.bg), color(theme.fg), map(D, this.min, this.max, 0, 1))); stroke(theme.sfg);
          } else {
            fill(lerpColor(color(theme.sfg), color(theme.sbg), map(D, this.min, this.max, 0, 1))); stroke(theme.sfg);
          }
          text(this.data.is_char ? String.fromCodePoint(D) : D, mouseX, mouseY);
        }
      }
    }
  }

  table() {
    rectMode(CENTER);
    textAlign(CENTER, CENTER);
    for (let r = 0; r < this.data.data[this.step].length; r++) {
      for (let c = 0; c < this.data.data[this.step][r].length; c++) {
        const D = this.data.data[this.step][r][c];
        const R = this.data.data[this.step].length;
        const C = this.data.data[this.step][r].length;
        const W = width / C;
        const H = height / R;
        const S = min(W, H);
        const X = (c + 0.5 - R / 2) * S + width / 2;
        const Y = (r + 0.5 - C / 2) * S + height / 2;
        if (this.data.indices[this.step].some(index => index[0] == r && index[1] == c)) {
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
}
