<?php

/**
 * @file
 * This file provides the configuration form for the Background Video module.
 */

/**
 * Implements hook_form().
 *
 * This function is to define the configuration form.
 */
function background_video_settings_form($form, &$form_state) {
  $form = array();
  
  $form['background_video_source_mp4'] = array(
    '#title' => t('.mp4 Video'),
    '#type' => 'managed_file',
    '#description' => t('Please upload a .mp4 file. MP4 adds support for Safari & IE.'),
    '#default_value' => filter_xss(variable_get('background_video_source_mp4', NULL)),
    '#upload_validators' => array('file_validate_extensions' => array('mp4')),
    '#upload_location' => 'public://background_video',
    '#required' => TRUE,
  );
  $form['background_video_source_webm'] = array(
    '#title' => t('.webm Video'),
    '#type' => 'managed_file',
    '#description' => t('Please upload a .webm file. WEBM adds support for Chrome, Firefox, & Opera.'),
    '#required' => TRUE,
    '#default_value' => variable_get('background_video_source_webm', NULL),
    '#upload_validators'  => array('file_validate_extensions' => array('webm')),
    '#upload_location' => 'public://background_video',
  );
  $form['background_video_source_ogv'] = array(
    '#title' => t('.ogv Video'),
    '#type' => 'managed_file',
    '#description' => t('Provide upload a .ogg video. OGV adds support to different browsers.'),
    '#required' => TRUE,
    '#default_value' => variable_get('background_video_source_ogv', NULL),
    '#upload_validators'  => array('file_validate_extensions' => array('ogv')),
    '#upload_location' => 'public://background_video',
  );
  $form['background_video_id'] = array(
    '#title' => t('ID/Class Name'),
    '#type' => 'textfield',
    '#description' => t('Provide the specific ID/Class to which you want to add the background video. Prepend # with ID or . with class'),
    '#required' => TRUE,
    '#default_value' => variable_get('background_video_id', 'body'),
  );
  $form['background_video_control_position'] = array(
    '#title' => t('Control Position'),
    '#type' => 'textfield',
    '#description' => t('Provide the specific ID where controls like Play/Pause and Mute/Unmute are placed. Leave blank if you do not want that user can control the background video.'),
    '#default_value' => variable_get('background_video_control_position', '#footer'),
  );
  $form['background_video_source_poster'] = array(
    '#title' => t('Video Poster'),
    '#type' => 'managed_file',
    '#description' => t('Provide the poster for the video.'),
    '#required' => TRUE,
    '#default_value' => variable_get('background_video_source_poster', NULL),
    '#upload_validators'  => array('file_validate_extensions' => array('gif jpg jpeg png')),
    '#upload_location' => 'public://background_video',
  );
  $form['background_video_loop'] = array(
    '#title' => t('Loop Video'),
    '#type' => 'checkbox',
    '#description' => t('Select the checkbox if you want to play the video in the loop.'),
    '#default_value' => variable_get('background_video_loop', 1),
  );
  $form['background_video_autoplay'] = array(
    '#title' => t('Autoplay Video'),
    '#type' => 'checkbox',
    '#description' => t('Select the checkbox if you want to autpplay the video when the page is loaded.'),
    '#default_value' => variable_get('background_video_autoplay', 1),
  );
  $form['#submit'][] = 'background_video_settings_form_submit';
  return system_settings_form($form);
}

/**
 * Submit Handler for the configuration form.
 */
function background_video_settings_form_submit($form, &$form_state) {
  _background_video_file_save('mp4', $form_state);
  _background_video_file_save('ogv', $form_state);
  _background_video_file_save('webm', $form_state);
  _background_video_file_save('poster', $form_state);
}

/**
 * Callback function to save the file permanetly and file usage add.
 */
function _background_video_file_save($type, $form_state) {
  $file = file_load($form_state['values']['background_video_source_' . $type]);
  if (is_object($file)) {
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
    file_usage_add($file, 'background_video', 'background_video', 1);
  } 
}
