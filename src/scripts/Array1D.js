class Array1D {
  constructor(data) {
    this.data = data;
    this.step = 0;
    this.min = min(min(this.data.data[this.step]), 0);
    this.max = max(max(this.data.data[this.step]), 0);
  }

  next(step = 1) {
    if (this.step + step < this.data.data.length) {
      this.step += step;
    } else {
      this.step = this.data.data.length - 1;
    }
  }

  graph() {
    rectMode(CORNERS);
    for (let i = 0; i < this.data.data[this.step].length; i++) {
      const D = this.data.data[this.step][i];
      const X0 = (i + 0.0) * width / this.data.data[this.step].length;
      const Y0 = map(0, this.min, this.max, height, 0);
      const X1 = (i + 1.0) * width / this.data.data[this.step].length;
      const Y1 = map(D, this.min, this.max, height, 0);
      fill(fg); stroke(bg);
      rect(X0, Y0, X1, Y1);
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
      fill(bg); stroke(fg);
      square(X, Y, S);
      fill(fg); stroke(bg);
      text(D, X, Y);
    }
  }
}
