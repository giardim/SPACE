const controls = { play: 0 };
const space = { Array1D, Array2D, Vector1D, Vector2D, Stack };
const theme = {};
const svg = {
  arrowl: {
    path: new Path2D('M9.4 233.4c-12.5 12.5-12.5 32.8 0 45.3l160 160c12.5 12.5 32.8 12.5 45.3 0s12.5-32.8 0-45.3L109.2 288 416 288c17.7 0 32-14.3 32-32s-14.3-32-32-32l-306.7 0L214.6 118.6c12.5-12.5 12.5-32.8 0-45.3s-32.8-12.5-45.3 0l-160 160z'),
    x: 0, y: 63.92500305175781, w: 447.9750061035156, h: 384.14996337890625
  },
  arrowr: {
    path: new Path2D('M438.6 278.6c12.5-12.5 12.5-32.8 0-45.3l-160-160c-12.5-12.5-32.8-12.5-45.3 0s-12.5 32.8 0 45.3L338.8 224 32 224c-17.7 0-32 14.3-32 32s14.3 32 32 32l306.7 0L233.4 393.4c-12.5 12.5-12.5 32.8 0 45.3s32.8 12.5 45.3 0l160-160z'),
    x: 0, y: 63.92500305175781, w: 447.9750061035156, h: 384.14996337890625
  }
};

let data = {};
let data_structure = {};
let view = '';

function setup() {
  createCanvas($('#canvas').width(), $('#canvas').height());
  $('#canvas').append($('canvas'));
  setTimeout(windowResized);
  $('main').remove();

  $('#sidebar-toggle').click(() => {
    $('#sidebar').toggleClass('active');
    const interval = setInterval(windowResized);
    setTimeout(() => clearInterval(interval), 500);
  });
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

  $('html').on('dragover', e => e.preventDefault()).on('drop', e => {
    e.preventDefault();
    e.originalEvent.dataTransfer.items?.forEach(async (item) => {
      if (item.kind == 'file') {
        data = JSON.parse(await item.getAsFile().text());
        $('#data-structures').empty();
        for (const key of Object.keys(data)) {
          $('#data-structures').append(`<button class="data-structure" data-key="${key}"><code>${key}</code></button>`);
        }
        $('.data-structure').click(function () {
          const key = $(this).attr('data-key');
          data_structure = new space[data[key].type](data[key]);
          $('#data-type>button').text(data[key].type || ' ');
          $('.data-structure').removeClass('active');
          $(this).addClass('active');
          $('#step').val(data_structure.getStep().toString().padStart((data_structure.data.data.length - 1).toString().length, 0));
          $('#step').attr('size', (data_structure.data.data.length - 1).toString().length);
          $('#steps').text(data_structure.data.data.length - 1);
          $('#step-slider').val(data_structure.getStep());
          $('#step-slider').attr('max', data_structure.data.data.length - 1);
          controls.play = 0; $('#controls').attr('data-play', 1);
        });
        $('.data-structure').eq(0).click();
        $('#view-settings button').eq(0).click();
        $('#dropzone').removeClass('active');
        $('#sidebar, #sidebar-h, #player-h, #data-structures, #canvas, #manual, #controls').addClass('active');
        const interval = setInterval(windowResized); setTimeout(() => clearInterval(interval), 500);
      }
    });
  });

  $('#prev').click(() => data_structure.prev());
  $('#play').click(() => $('#controls').attr('data-play', Number(!(controls.play = !controls.play))));
  $('#next').click(() => data_structure.next());
  $('#step').change(() => data_structure.setStep($('#step').val())).val(0).attr('size', 1);
  $('#step-slider').on('input', () => data_structure.setStep($('#step-slider').val())).val(0);
  $('#fullscreen').click(() => {
    const enabled =
      document.fullscreenEnabled ||
      document.msFullscreenEnabled ||
      document.mozFullScreenEnabled ||
      document.webkitFullscreenEnabled;
    if (!enabled) {
      throw new Error('Fullscreen not enabled in this browser.');
    }
    if ($('#canvas')[0].requestFullscreen) {
      $('#canvas')[0].requestFullscreen();
    } else if ($('#canvas')[0].msRequestFullscreen) {
      $('#canvas')[0].msRequestFullscreen();
    } else if ($('#canvas')[0].mozRequestFullScreen) {
      $('#canvas')[0].mozRequestFullScreen();
    } else if ($('#canvas')[0].webkitRequestFullscreen) {
      $('#canvas')[0].webkitRequestFullscreen();
    }
  });

  $('#controls').attr('data-play', 1);
  $('#dropzone').addClass('active');
  $('#sidebar, #sidebar-h, #player-h, #data-structures, #canvas, #manual, #controls').removeClass('active');
  const interval = setInterval(windowResized); setTimeout(() => clearInterval(interval), 500);
}

function draw() {
  background(theme.bg);
  data_structure[view]?.();
  if (controls.play) {
    controls.play = data_structure.next?.();
    if (!controls.play) {
      $('#controls').attr('data-play', 1);
    }
  }
}

function windowResized() {
  resizeCanvas($('#canvas').width(), $('#canvas').height());
}
