<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */


/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
/* -- Delete this line if you want to use this function
function camsys_preprocess_maintenance_page(&$variables, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  camsys_preprocess_html($variables, $hook);
  camsys_preprocess_page($variables, $hook);
}
// */

/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
/* -- Delete this line if you want to use this function
function camsys_preprocess_html(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // The body tag's classes are controlled by the $classes_array variable. To
  // remove a class from $classes_array, use array_diff().
  //$variables['classes_array'] = array_diff($variables['classes_array'], array('class-to-remove'));
}
// */

/**
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function camsys_preprocess_page(&$variables, $hook) {
    drupal_add_css('//maxcdn.bootstrapcdn.com/font-awesome/4.2.0/css/font-awesome.min.css', 'external');
    // remove "There is currently no content classified with this term." text from empty taxonomy pages
    if(isset($variables['page']['content']['system_main']['no_content'])) {
        unset($variables['page']['content']['system_main']['no_content']);
    }


}
// */

/**
 * Override or insert variables into the node templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function camsys_preprocess_node(&$variables, $hook) {
    // get path url after last "/" and add it to node class
    $path_array = explode('/', drupal_get_path_alias('node/'.$variables['nid']));
    $variables['classes_array'][] = 'node-' . array_pop($path_array);
  // Optionally, run node-type-specific preprocess functions, like
  // camsys_preprocess_node_page() or camsys_preprocess_node_story().
  $function = __FUNCTION__ . '_' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }


}
// */

/**
 * Override or insert variables into the comment templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function camsys_preprocess_comment(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the region templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */
/* -- Delete this line if you want to use this function
function camsys_preprocess_region(&$variables, $hook) {
  // Don't use Zen's region--sidebar.tpl.php template for sidebars.
  //if (strpos($variables['region'], 'sidebar_') === 0) {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('region__sidebar'));
  //}
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function camsys_preprocess_block(&$variables, $hook) {
  // Add a count to all the blocks in the region.
  // $variables['classes_array'][] = 'count-' . $variables['block_id'];

  // By default, Zen will use the block--no-wrapper.tpl.php for the main
  // content. This optional bit of code undoes that:
  //if ($variables['block_html_id'] == 'block-system-main') {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('block__no_wrapper'));
  //}
}
// */

// custom breadcrumb based on zen and adapted to customize taxonomy pages
function camsys_breadcrumb($variables) {
    $breadcrumb = $variables['breadcrumb'];
    $output = '';

    // Determine if we are to display the breadcrumb.
    $show_breadcrumb = theme_get_setting('zen_breadcrumb');
    if ($show_breadcrumb == 'yes' || $show_breadcrumb == 'admin' && arg(0) == 'admin') {

        // Optionally get rid of the homepage link.
        $show_breadcrumb_home = theme_get_setting('zen_breadcrumb_home');
        if (!$show_breadcrumb_home) {
            array_shift($breadcrumb);
        }

        // Return the breadcrumb with separators.
        if (!empty($breadcrumb)) {

            // if taxonomy item then reset breadbrumb trail to match menu system
            if (arg(0)=='taxonomy' && arg(1)=='term') {
                $term = taxonomy_term_load(arg(2));
                if ($term->vid==3) {
                    $breadcrumb = menu_get_active_breadcrumb();
                }
            }

            $breadcrumb_separator = filter_xss_admin(theme_get_setting('zen_breadcrumb_separator'));
            $trailing_separator = $title = '';
            if (theme_get_setting('zen_breadcrumb_title')) {
                $item = menu_get_item();
                if (!empty($item['tab_parent'])) {
                    // If we are on a non-default tab, use the tab's title.
                    $breadcrumb[] = check_plain($item['title']);
                }
                else {
                    $breadcrumb[] = drupal_get_title();
                }
            }
            elseif (theme_get_setting('zen_breadcrumb_trailing')) {
                $trailing_separator = $breadcrumb_separator;
            }

            // Provide a navigational heading to give context for breadcrumb links to
            // screen-reader users.
            if (empty($variables['title'])) {
                $variables['title'] = t('You are here');
            }
            // Unless overridden by a preprocess function, make the heading invisible.
            if (!isset($variables['title_attributes_array']['class'])) {
                $variables['title_attributes_array']['class'][] = 'element-invisible';
            }

            // Build the breadcrumb trail.
            $output = '<nav class="breadcrumb" role="navigation">';
            $output .= '<h2' . drupal_attributes($variables['title_attributes_array']) . '>' . $variables['title'] . '</h2>';
            $output .= '<ol><li>' . implode($breadcrumb_separator . '</li><li>', $breadcrumb) . $trailing_separator . '</li></ol>';
            $output .= '</nav>';
        }
    }

    return $output;
}
/*
function camsys_preprocess_menu_link(&$vars) {
    dsm($vars);
}
*/

// alter search block form
function camsys_form_alter (&$form, &$form_state, $form_id) {
  if ($form_id == 'search_block_form') {
    $form['actions']['submit'] = array(
        '#type' => 'submit',
        '#value' => '',
        '#attributes' => array( 'style' => array( 'display: none' )), // hide the input field
        '#suffix' => '<button type="submit" class="btn btn-primary"><i class="fa fa-search"></i></button>',
    );
  }
    if ($form_id == 'global_filter_1') {
        $form['field_tags']['und']['#attributes']['class'] = array('auto_search_filter');
        $form['submit']['#value'] = 'Search';
        $form['submit']['#attributes']['style'] = array( 'display: none' );
        $form['submit']['#suffix'] = '<button type="submit" class="btn btn-primary"><i class="fa fa-search"></i></button>';
        $form['#action'] = '/search-results';
        //dsm($form);
    }

}

function camsys_global_filter_value_alter($name, &$value) {
    // Global Filter for city using Smart IP.
    if ($name == 'field_tags' && isset($value[0]['name'])) {
        $value = $value[0]['name'];
    }
}

