const space = { Array1D, Array2D };
const theme = {};

let data = {};
let data_structure = {};
let view = '';

function setup() {
  createCanvas($('#canvas').width(), $('#canvas').height());
  $('#canvas').append($('canvas'));
  setTimeout(windowResized);
  $('main').remove();

  $('#theme-toggle').click(() => $('#themes').toggleClass('active'));
  $('.theme').click(function () {
    $('html').attr('class', $(this).attr('id'));
    theme.bg = $('html').css('--bg');
    theme.fg = $('html').css('--fg');
    theme.sbg = $('html').css('--sidebar-bg');
    theme.sfg = $('html').css('--sidebar-fg');
    $('.theme').removeClass('active');
    $(this).addClass('active');
    localStorage.setItem('theme', $(this).attr('id'));
  });
  $(`#${localStorage.getItem('theme') || 'navy'}`).click();

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
          $('#data-type>button').text(data[key].type || ' ');
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
  background(theme.bg);
  data_structure[view]?.();
  data_structure.next?.();
}

function windowResized() {
  resizeCanvas($('#canvas').width(), $('#canvas').height());
}
