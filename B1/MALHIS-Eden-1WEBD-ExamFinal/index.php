<?php include_once("header.php"); ?>
<section>
    <h1>Welcome in your Task Manager</h1>
    <?php
    if (isConnected()): ?>
        <div class="home">
            <!--affichage des tâches -->
            <div class="taskBlock">
                <div class="mytasks">
                    <h2> My Tasks</h2>
                    <?php include("get_data.php"); ?>
                    <!--creation nouvelle tâche (overlay en page newtask), idem pour les catégories-->
                    <div class="createTask">
                        <h4>Add a new task</h4>
                    </div>
                </div>
                <div class="overlay newtask">
                    <div class="insideoverlay">
                        <?php include("newtask.php") ?>
                    </div>
                </div>
                <div class="createCategory">
                    <h4>Add a new category</h4>
                </div>
                <div class="overlay newcategory">
                    <div class="insideoverlay">
                        <?php include("newcategory.php") ?>
                    </div>
                </div>
            </div>
            <div class="bear">
                <img class="bearimg" src="Img/Happy.png">
            </div>
        </div>
    <?php else: ?>
        <h4><a href="login.php">Log in</a> to see your tasks.</h4>
    <?php endif; ?>
</section>

<?php include "footer.php"; ?>