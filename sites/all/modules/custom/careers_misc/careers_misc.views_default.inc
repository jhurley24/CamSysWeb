<?php
/**
 * @file
 * careers_misc.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function careers_misc_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'careers_slideshow';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'file_managed';
  $view->human_name = 'Careers Slideshow';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Careers Slideshow';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['style_options']['optionset'] = 'cs_flexslider_settings';
  $handler->display->display_options['style_options']['captionfield'] = 'field_file_image_title_text';
  $handler->display->display_options['row_plugin'] = 'file';
  $handler->display->display_options['row_options']['links'] = 1;
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = '';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['ellipsis'] = FALSE;
  /* Field: File: Title Text */
  $handler->display->display_options['fields']['field_file_image_title_text']['id'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['table'] = 'field_data_field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['field'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['label'] = '';
  $handler->display->display_options['fields']['field_file_image_title_text']['element_label_colon'] = FALSE;
  /* Filter criterion: File: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'file_managed';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'image' => 'image',
  );
  /* Filter criterion: File: Image Category (field_image_category) */
  $handler->display->display_options['filters']['field_image_category_tid']['id'] = 'field_image_category_tid';
  $handler->display->display_options['filters']['field_image_category_tid']['table'] = 'field_data_field_image_category';
  $handler->display->display_options['filters']['field_image_category_tid']['field'] = 'field_image_category_tid';
  $handler->display->display_options['filters']['field_image_category_tid']['value'] = array(
    1329 => '1329',
  );
  $handler->display->display_options['filters']['field_image_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_image_category_tid']['vocabulary'] = 'image_category';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['careers_slideshow'] = $view;

  $view = new view();
  $view->name = 'tagline_image';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'file_managed';
  $view->human_name = 'Tagline Image';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Tagline Image';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'file';
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = '';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Filter criterion: File: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'file_managed';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'image' => 'image',
  );
  /* Filter criterion: File: Image Category (field_image_category) */
  $handler->display->display_options['filters']['field_image_category_tid']['id'] = 'field_image_category_tid';
  $handler->display->display_options['filters']['field_image_category_tid']['table'] = 'field_data_field_image_category';
  $handler->display->display_options['filters']['field_image_category_tid']['field'] = 'field_image_category_tid';
  $handler->display->display_options['filters']['field_image_category_tid']['value'] = array(
    1328 => '1328',
  );
  $handler->display->display_options['filters']['field_image_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_image_category_tid']['vocabulary'] = 'image_category';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['tagline_image'] = $view;

  return $export;
}
