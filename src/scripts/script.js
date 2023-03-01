const space = { Array1D };

let bg = '';
let fg = '';
let data = {};
let data_structure = {};
let view = '';

function setup() {
  createCanvas($('#canvas').width(), $('#canvas').height());
  $('#canvas').append($('canvas'));
  setTimeout(windowResized);
  $('main').remove();

  rectMode(CORNERS);

  $('#theme-toggle').click(() => $('#themes').toggleClass('active'));
  $('.theme').click(function () {
    $('html').attr('class', $(this).attr('id'));
    bg = $('html').css('--bg');
    fg = $('html').css('--fg');
    $('.theme').removeClass('active');
    $(this).addClass('active');
  });
  $('#navy').click();

  $('#view-settings button').click(function () {
    view = $(this).attr('id');
    $('#view-settings button').removeClass('active');
    $(this).addClass('active');
  });

  $('canvas').on('dragover', e => e.preventDefault()).on('drop', e => {
    e.preventDefault();
    e.originalEvent.dataTransfer.items?.forEach(async (item) => {
      if (item.kind === 'file') {
        data = JSON.parse(await item.getAsFile().text());
        for (const [key, value] of Object.entries(data)) {
          $('#data-structures').append(`<button class="data-structure" data-key="${key}"><code>${key}</code></button>`);
        }
        $('.data-structure').click(function () {
          const key = $(this).data('key');
          data_structure = new space[data[key].type](data[key]);
          $('#data-type').html(`<h1>${data[key].type || ' '}</h1>`);
          $('.data-structure').removeClass('active');
          $(this).addClass('active');
        });
        $('.data-structure').eq(0).click();
        $('#view-settings button').eq(0).click();
      }
    });
  });
}

function draw() {
  background(bg);
  data_structure[view]?.();
  data_structure.next?.();
}

function windowResized() {
  resizeCanvas($('#canvas').width(), $('#canvas').height());
}
