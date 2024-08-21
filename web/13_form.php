<!-- PHP code to show CRUD Operations -->

<?php
$conn = new mysqli('localhost', 'root', '', 'database');

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

if (isset($_POST['create'])) {
    $name = $_POST['name'];
    $email = $_POST['email'];

    $sql = "INSERT INTO users (name, email) VALUES ('$name', '$email')";
    if ($conn->query($sql) === TRUE) {
        echo "New record created successfully<br>";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
}

$result = $conn->query("SELECT * FROM users");

if (isset($_POST['update'])) {
    $id = $_POST['id'];
    $name = $_POST['name'];
    $email = $_POST['email'];

    $sql = "UPDATE users SET name='$name', email='$email' WHERE id=$id";
    if ($conn->query($sql) === TRUE) {
        echo "Record updated successfully<br>";
    } else {
        echo "Error updating record: " . $conn->error;
    }
}

if (isset($_POST['delete'])) {
    $id = $_POST['id'];

    $sql = "DELETE FROM users WHERE id=$id";
    if ($conn->query($sql) === TRUE) {
        echo "Record deleted successfully<br>";
    } else {
        echo "Error deleting record: " . $conn->error;
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Simple CRUD Application</title>
</head>
<body>
    <h2>Create a new user</h2>
    <form method="POST">
        Name: <input type="text" name="name" required>
        Email: <input type="email" name="email" required>
        <button type="submit" name="create">Create</button>
    </form>

    <h2>Update an existing user</h2>
    <form method="POST">
        User ID: <input type="number" name="id" required>
        New Name: <input type="text" name="name" required>
        New Email: <input type="email" name="email" required>
        <button type="submit" name="update">Update</button>
    </form>

    <h2>Delete a user</h2>
    <form method="POST">
        User ID: <input type="number" name="id" required>
        <button type="submit" name="delete">Delete</button>
    </form>

    <h2>Users List</h2>
    <table border="1">
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Email</th>
        </tr>
        <?php while ($row = $result->fetch_assoc()): ?>
        <tr>
            <td><?php echo $row['id']; ?></td>
            <td><?php echo $row['name']; ?></td>
            <td><?php echo $row['email']; ?></td>
        </tr>
        <?php endwhile; ?>
    </table>

    <?php $conn->close(); ?>
</body>
</html>
