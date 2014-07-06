<?php
/**
 * See page.tpl.php
 */
?>
<?php
  drupal_add_css( path_to_theme() . '/css/scrolling-front-page.css', array( 'group' => CSS_THEME ) );
  drupal_add_js(  path_to_theme() . '/js/scrolling-front-page.js' );
?>
<div id="page">

  <header class="header" id="header" role="banner">

    <?php print render($page['header']); ?>
    
    <?php if ($title): ?>
        <h1 class="page__title title" id="page-title"><?php print $title; ?></h1>
    <?php endif; ?>

  </header>

  <div id="main">

    <div id="content" class="column" role="main">
      <a id="main-content"></a>

      <?php print $messages; ?>

      <?php print render($page['content']); ?>
    </div>

  </div>

  <?php print render($page['footer']); ?>

</div>

<?php print render($page['bottom']); ?>
