<?php
/**
 * @file
 * Returns the HTML for the footer region.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728140
 */
?>
<?php if ($content): ?>
  <footer id="footer" class="<?php print $classes; ?>">
    <div class="inner">
      <?php print $content; ?>
      <div class="block social-links">
        <a href="https://www.facebook.com/Camsys" target="_blank"><i class="fa fa-facebook"></i></a>
        <a href="https://twitter.com/Camsys" target="_blank"><i class="fa fa-twitter"></i></a>
        <a href="http://www.linkedin.com/company/cambridge-systematics/products" target="_blank"><i class="fa fa-linkedin"></i></a>
      </div>
      <div class="copyright">
        &copy; Copyright 2016 Cambridge Systematics. All rights reserved
      </div>
    </div>


  </footer>
<?php endif; ?>
