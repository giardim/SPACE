const controls = { play: 0, volume: 100 };
const space = { Array1D, Array2D };
const theme = {};
const FMIN = 200;
const FMAX = 2000;

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
        for (const [key, value] of Object.entries(data)) {
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
        $('#sidebar, #sidebar-h, #player-h, #data-structures, #canvas, #manual, #controls').addClass('active');
        const interval = setInterval(windowResized); setTimeout(() => clearInterval(interval), 500);
      }
    });
  });

  $('#prev').click(() => data_structure.prev());
  $('#play').click(() => {
    controls.play = !controls.play;

    if (controls.play) {
      $('#controls').attr('data-play', 0);
      data_structure.sound(1);
    } else {
      $('#controls').attr('data-play', 1);
      data_structure.sound(0);
    }
  });
  $('#next').click(() => data_structure.next());
  $('#volume-button').click(() => {
    controls.muted = !controls.muted;

    if (controls.volume > 00) {
      $('#controls').attr('data-volume', 'low');
      $('#volume-slider').val(controls.volume);
    }
    if (controls.volume > 50) {
      $('#controls').attr('data-volume', 'high');
      $('#volume-slider').val(controls.volume);
    }
    if (controls.volume == 0 || controls.muted) {
      $('#controls').attr('data-volume', 'muted');
      $('#volume-slider').val(0);
    }
  });
  $('#volume-slider').on('input', () => {
    controls.volume = $('#volume-slider').val();
    controls.muted = $('#volume-slider').val() == 0;

    if (controls.volume > 00) {
      $('#controls').attr('data-volume', 'low');
      $('#volume-slider').val(controls.volume);
    }
    if (controls.volume > 50) {
      $('#controls').attr('data-volume', 'high');
      $('#volume-slider').val(controls.volume);
    }
    if (controls.volume == 0 || controls.muted) {
      $('#controls').attr('data-volume', 'muted');
      $('#volume-slider').val(0);
    }
  });
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

  $('#controls').attr('data-play', 1).attr('data-volume', 'high');
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
      data_structure.sound(0);
    }
  }
}

function windowResized() {
  resizeCanvas($('#canvas').width(), $('#canvas').height());
}
