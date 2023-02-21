const space = { Array1D };

let data = {};
let data_structure = {};
let view = '';

function setup() {
  createCanvas(windowWidth * 0.75, windowHeight * 0.75);
  $('#canvas').append($('canvas'));
  $('main').remove();

  fill('#BCBDD0');
  stroke('#161923');
  rectMode(CORNERS);

  $('canvas').on('dragover', e => e.preventDefault()).on('drop', e => {
    e.preventDefault();
    e.originalEvent.dataTransfer.items?.forEach(async (item) => {
      if (item.kind === 'file') {
        data = JSON.parse(await item.getAsFile().text());
        for (const [key, value] of Object.entries(data)) {
          $('#data_structures').append(`<button class="data_structure" data-key="${key}">${key}</button>`);
        }
        $('.data_structure').on('click', function () {
          const key = $(this).data('key');
          data_structure = new space[data[key].type](data[key]);
          $('#player_h').html(`<h1> </h1><h2>${data[key].type}</h2>`);
        });
        $('.data_structure').eq(0).trigger('click');
        view = 'graph';
      }
    });
  });
}

function draw() {
  background('#161923');
  data_structure[view]?.();
  data_structure.next?.();
}

function windowResized() {
  resizeCanvas(windowWidth * 0.75, windowHeight * 0.75);
}
