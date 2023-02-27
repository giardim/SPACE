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
    for (let i = 0; i < this.data.data[this.step].length; i++) {
      const D = this.data.data[this.step][i];
      const X0 = (i + 0) * width / this.data.data[this.step].length;
      const Y0 = map(0, this.min, this.max, height, 0);
      const X1 = (i + 1) * width / this.data.data[this.step].length;
      const Y1 = map(D, this.min, this.max, height, 0);
      rect(X0, Y0, X1, Y1);
    }
  }

  table() {

  }
}
