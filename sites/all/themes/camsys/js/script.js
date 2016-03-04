/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.my_custom_behavior = {
  attach: function(context, settings) {

    // Place your code here.
    /* mobile menu - add action */
    $('.region-header .main-menu .block-title').click(function() {
      if ($('.main-menu').hasClass('active')) {
        $('.main-menu').removeClass('active');
      }
      else {
        $('.main-menu').addClass('active');
      }
    });

    // landing page image background
    // find image from group right and add it as background for div

    var group_right = '.node-type-landing-page .node .group-right';
    var bk_img = $(group_right+' img').attr('src');
    $(group_right).css('background-image', 'url('+bk_img+')');
    

    // remove links from menu items with .nolink class
    $('.block-menu-block li a.nolink').attr('href', 'javascript:void(0)');
    //$('.section-services-products .main-menu li.services-products > .menu > li > .menu > li > a').attr('href', 'javascript:void(0)');
    //$('.section-services-products .sidebar-menu .menu-block-wrapper > .menu > li > .menu > li > a').attr('href', 'javascript:void(0)');
    $('.section-services-products .main-menu li.services-products > .menu > li > .menu > li, .main-menu li.services-products > .menu > li > .menu > li').each(function() {
      $(this).addClass('is-expanded');
      $(this).children('a').attr('href', 'javascript:void(0)');
    });
    // add active state to sidebar and top menu on rollover
    $('.block-menu-block .menu li.is-expanded').click(function() {
      if ($(this).hasClass('active')) {
        $(this).removeClass('active');
      }
      else {
        $(this).addClass('active');
      }
    });

    // activate ps item list
    $('.ps-term-list .item-list h3').click(function() {
      if ($(this).parent().hasClass('active')) {
        $(this).parent().removeClass('active');
      }
      else {
        $(this).parent().addClass('active');
      }
    });

    // add global views search term to page title
    var search_term = $('form.global-filter input[type=text]').attr('value');
    if (search_term) {
      $('h1.title').text(search_term);
    }

    // toggle share block
    $('.share').click(function() {
      $('.sharethis-wrapper').addClass('active');
    });

  }
};


})(jQuery, Drupal, this, this.document);
