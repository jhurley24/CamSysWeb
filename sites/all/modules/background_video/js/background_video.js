/**
 * @file
 * This file is basically provides the jquery function to append video.
 */

(function ($) {
  'use strict';
  Drupal.behaviors.jquery_videobackground = {
    attach: function (context, settings) {
      var autoplay = settings.background_video.auto_play;
      var auto_play;
      if (autoplay === 0) {
        auto_play = false;
      }
      else {
        auto_play = true;
      }
      $(settings.background_video.video_id).prepend('<div class="video-background"></div>');
      $('.video-background').videobackground({
        videoSource: [[settings.background_video.mp4, 'video/mp4'],
          [settings.background_video.webm, 'video/webm'],
          [settings.background_video.ogv, 'video/ogg']],
        controlPosition: settings.background_video.control_pos,
        autoplay: auto_play,
        loop: settings.background_video.loop,
        resize: true,
        resizeTo: 'document',
        controlText: ['Play', 'Pause', 'Mute', 'Unmute']
      });
    }
  };
}(jQuery));
