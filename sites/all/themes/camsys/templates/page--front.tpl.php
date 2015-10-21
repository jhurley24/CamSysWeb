<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>

<div id="page">

  <header class="header" id="header" role="banner">

    <?php if ($logo): ?>
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="header__logo" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" class="header__logo-image" /></a>
    <?php endif; ?>

    <?php if ($site_name || $site_slogan): ?>
      <div class="header__name-and-slogan" id="name-and-slogan">
        <?php if ($site_name): ?>
          <h1 class="header__site-name" id="site-name">
            <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" class="header__site-link" rel="home"><span><?php print $site_name; ?></span></a>
          </h1>
        <?php endif; ?>

        <?php if ($site_slogan): ?>
          <div class="header__site-slogan" id="site-slogan"><?php print $site_slogan; ?></div>
        <?php endif; ?>
      </div>
    <?php endif; ?>

    <?php if ($secondary_menu): ?>
      <nav class="header__secondary-menu" id="secondary-menu" role="navigation">
        <?php print theme('links__system_secondary_menu', array(
          'links' => $secondary_menu,
          'attributes' => array(
            'class' => array('links', 'inline', 'clearfix'),
          ),
          'heading' => array(
            'text' => $secondary_menu_heading,
            'level' => 'h2',
            'class' => array('element-invisible'),
          ),
        )); ?>
      </nav>
    <?php endif; ?>

    <?php print render($page['header']); ?>

  </header>

  <div id="main">

    <div id="content" class="column" role="main">
      <?php print render($page['highlighted']); ?>
      <a id="main-content"></a>
      <?php print $messages; ?>
      <?php print render($tabs); ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <!-- home page content here -->
      <div class="help-form">
        <div class="inner">
          <p>We are transportation specialists. We provide innovative policy
            and planning solutions, objective analysis, and technology
            applications. We are committed to making transportation better
            for future generations. </p>
          <p class="feature">How can we help you?</p>
          <form>
            <div class="form-item form-type-textfield form-item-search-block-form">
              <input title="How can we help you?" type="text" id="help-form" name="search_block_form" value="" class="form-text"><button type="submit" class="btn btn-primary"><i class="fa fa-search"></i></button>
            </div>
          </form>
        </div>

      </div>
      <div class="case-study">
        <div class="inner">
          <h3>Case Study</h3>
          <div class="title">The Ubiquitous, Disappearing Taxi</div>
          <div class="description">
            We’re helping municipalities plan to make the most
            of the shift away from taxi cabs.</div>
          <div class="readmore"><a href="#">Read the study »</a></div>
        </div>

      </div>
      <div class="cs-sections">
        <div class="section about">
          <div class="title">ABOUT CS</div>
          <div lass="description">Lorem ipsum dolor sit, consectetur adipi elit. Suspendisse susci pit urna, a sollicit est</div>
          <div class="readmore"><a href="#">Read more »</a></div>
        </div>
        <div class="section markets">
          <div class="title">Markets</div>
          <div class="description">Lorem ipsum dolor sit, consectetur adipi elit. Suspendisse susci pit urna, a sollicit est</div>
          <div class="readmore"><a href="#">Read more »</a></div>
        </div>
        <div class="section services-products">
          <div  class="title">Services & Products</div>
          <div lass="description">Lorem ipsum dolor sit, consectetur adipi elit. Suspendisse </div>
          <div class="readmore"><a href="#">Read more »</a></div>
        </div>
        <div class="section publications">
          <div class="title">Publications</div>
          <div lass="description">Lorem ipsum dolor sit, consectetur adipi elit. Suspendisse susci pit urna, a sollicit est</div>
          <div class="readmore"><a href="#">Read more »</a></div>
        </div>
        <div class="section insights">
          <div class="title">Insights</div>
          <div lass="description">Lorem ipsum dolor sit, consectetur adipi elit. Suspendisse susci pit urna, a sollicit est</div>
          <div class="readmore"><a href="#">Read more »</a></div>
        </div>
        <div class="section contact">
          <div class="title">Contact us</div>
          <div class="description">Lorem ipsum dolor sit, consectetur adipi elit. Suspendisse susci pit urna, a sollicit est</div>
          <div class="readmore"><a href="#">Read more »</a></div>
        </div>

      </div>

      <div class="news-events">
        <div class="news group-left">
          <h3>News</h3>
          <div class="item">
            <div class="title"><a href="#">Idaho DOT Statewide Freight Strategic Plan</a></div>
            <div class="description">Develop a freight plan that will improve safety
            operations for carriers, enhance system
            mobility, and support the economy and the
            vitality of the State.</div>
            <div class="readmore"><a href="#">Read more »</a></div>
          </div>
          <div class="item">
            <div class="title"><a href="#">Idaho DOT Statewide Freight Strategic Plan</a></div>
            <div class="description">Develop a freight plan that will improve safety
              operations for carriers, enhance system
              mobility, and support the economy and the
              vitality of the State.</div>
            <div class="readmore"><a href="#">Read more »</a></div>
          </div>
        </div>
        <div class="events group-right">
          <h3>Events</h3>
          <div class="item">
            <div class="title"><a href="#">Idaho DOT Statewide Freight Strategic Plan</a></div>
            <div class="description">Develop a freight plan that will improve safety
              operations for carriers, enhance system
              mobility, and support the economy and the
              vitality of the State.</div>
            <div class="readmore"><a href="#">Read more »</a></div>
          </div>
          <div class="item">
            <div class="title"><a href="#">Idaho DOT Statewide Freight Strategic Plan</a></div>
            <div class="description">Develop a freight plan that will improve safety
              operations for carriers, enhance system
              mobility, and support the economy and the
              vitality of the State.</div>
            <div class="readmore"><a href="#">Read more »</a></div>
          </div>
        </div>

      </div>


      <?php print render($page['content']); ?>
    </div>


  </div>

  <?php print render($page['footer']); ?>

</div>

<?php print render($page['bottom']); ?>
